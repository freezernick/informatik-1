Informatik-Projekt von Jakob Wagner und Nick Lamprecht    
12g - 19/20 Stormarnschule Ahrensburg

## Spielprinzip

Wie in fast allen Survival-Games geht es auch in Survisland darum sich in der Umgebung der Spielwelt Ressourcen bzw. Items zu sammeln, die es dem Spieler erlauben natürliche Gefahren wie Hunger und Durst als auch artifizielle Bedrohungen in Form von NPCs zu überwinden.

Alles funktioniert hierbei in festen Intervallen:   
- Jede Sekunde wird dem Spieler 0.2 Essens- und Trinkpunkte abgezogen   
- Alle 20 Minuten werden neue Items gespawnt    
- Nach 5 Minuten werden neue NPCs gespawnt    

Die Werte sind hier beispielhaft und werden sich im Laufe der Entwicklung noch häufig ändern.

## Spielablauf

Wenn das Spiel gestartet wird, öffnet sich zuallererst ein kleines Level, in dem sich der Spieler selbst nicht bewegen darf. Es dient lediglich dazu, dass wir einen abgeschirmten Bereich haben, wo dem Spieler ein Menü angezeigt wird, in dem er die Grafikeinstellungen anpassen kann.

![](https://survisland.de/assets/menucam.png)   
*Die linke Kamera ist die Spielfigur im Menü-Level*

![](https://survisland.de/assets/Uploads/1281f0a421/mainmenu.png)   
*Das Hauptmenü*


Wird das Spiel nun gestartet, wird das eigentliche Level geladen. Wenn die Map fertig geladen ist, geht es direkt los:
Die Timer für Items, NPCs und Spielerwerte starten sofort. Nun kann der Spieler sich frei bewegen, um die Gegend zu erkunden und sich auf die Suche nach Items zu machen. Die meisten Items können in den Städten gefunden werden (s. [Konzepterläuterungen](https://gitlab.com/f2p-entertainment/other/informatik-projekte/survisland/survisland/wikis/Konzepterkl%C3%A4rung#regionen)). Standardmäßig spawnt der Spieler in der Nähe einer Stadt, damit er sich ein anfängliches Loadout zusammensammeln kann. Wenn die Items der Stadt gesammelt sind, muss sich der Spieler zur nächsten Stadt begeben, die gerade noch am Horizont über den Wäldern erkannt werden kann.

Sowohl auf dem Weg als auch in den Städten trifft der Spieler dabei auf NPCs. Alle NPCs sind ebenso wie der Spieler bewaffnet. Befindet sich der Spieler in Sichtweite, bricht der NPC sofort seinen aktuellen Plan ab und nimmt die Verfolgung auf. Sobald sich der NPC in Schussweite gebracht hat, feuert er auf den Spieler bis dieser entweder außer Reichweite ist, oder einer der beiden Duellanten keine Hitpoints mehr hat.
Wird der Spieler erschossen, wird die Map wieder zur Menü-Map geändert: Das Spiel ist vorbei.

## Spielfunktionen

### Die Map

Die eigentliche Spielfläche bzw. das Terrain haben wir mit dem Landscape-Tool der UnrealEngine erstellt ([mehr im Stundenblog](https://gitlab.com/f2p-entertainment/other/informatik-projekte/survisland/survisland#stundenlog)).  
Das Level `World` ist unsere Karte. Dieses Level ist aus kleineren Levels zusammengesetzt. Im Sublevel `Root` befindet sich die Skybox, die Lichtquellen und ein paar Post-Processing Effektquellen wie z.B. für den Nebel. `WaterPlate` enthält ein einzelnes planares Static-Mesh mit unserem Ozean-Material. `Root` und `WaterPlate` sind über den vollständigen Aufenthalt im `World`-Level geladen.
Die eigentliche Umgebung mit den Städten und Wäldern ist in 4 Level aufgeteilt haben, die wir `MM`, `MN`, `NM` und `NN` genannt haben.
Der erste Buchstabe ist der x-Index des Levels und der zweite der y-Index. Wir haben Buchstaben genommen um mit kürzeren Namen eine größere Map erstellen zu können (26² anstatt 10² Maps bei einem Index pro Achse). Darüber hinaus haben wir nicht bei `A` angefangen, damit wir ggf. noch Maps nach vorne einschieben können, ohne negative Indizes zu verwenden oder alle Sublevel umbenennen zu müssen.
Diese vier Sublevels sind alle etwa 1km² groß und werden abhängig von der Position des Spielers geladen. Befindet der Spieler sich an der markierten Position (rot) kann der schraffierte Bereich entladen werden und wir sparen so Ressourcen auf dem Computer des Nutzers.

![](https://survisland.de/assets/Uploads/composition.png?vid=3)   
*Die Minimap des WorldComposition-Tools*


### Spieler

In der UnrealEngine besteht ein Spieler aus zwei Objekten:
Dem Pawn, meist ein Skeletal-Mesh, er ist die (visuelle) Repräsentation des Spielers und dem (Player)-Controller, der im weitesten Sinne die Logik enthält.

Der Grund hierfür ist, dass ein Spieler in einem Spiel unterschiedliche Pawns haben kann, aber die eigentlichen Daten dieselben bleiben.
Beispiel:

Der Spieler startet als menschliche Figur in der Welt. Steigt er nun in ein Auto, würde der Controller den Pawn der Figur zurücklassen (und despawnen) und Beginnen das Auto zu steuern. Möchte der Spieler das Auto nach einer Weile wider verlassen, kann ein neuer Pawn gespawnt werden, den der Controller dann übernehmen kann.
So lässt sich Logik, die für den Spieler an sich bzw. das Spiel relevant sind (z.B. die Punktzahl) von Logik der Figur (z.B. Blinker und Licht an einem Auto) voneinander trennen.

Der Spieler kann sich natürlich innerhalb der Map bewegen. Diese Funktionalität ist nativer Teil des [ACharacter](https://docs.unrealengine.com/en-US/API/Runtime/Engine/GameFramework/ACharacter/index.html), einem Child des Pawns. Darüber hinaus haben wir die Funktion eingebaut, dass sich der Spieler Ducken kann. Die Animation dafür kommt aus dem [Animation Starter Pack](https://www.unrealengine.com/marketplace/en-US/slug/animation-starter-pack) von Epic Games, den Entwicklern der UnrealEngine.

#### Bedürfnisse

![](https://survisland.de/assets/status.png)   
*Statusleisten des Spielers*

Der Spieler hat einen begrenzten Healthpool (rot) von 100 Hitpoints (HP). Sowohl Treffer durch gegnerische NPCs, als auch Hunger und Durst können dem Spieler HP abziehen.
Der Hunger (braun) und der Durst (blau) werden nur in einem festen Intervall größer und werden nicht durchs Gameplay beeinflusst. Die Anzeige ist hierbei allerdings die Sättigung und nicht der Hunger selber. Das heißt, dass der Statusbalken sich dem Nullpunkt nähert.
Wird ein Wert null, wird pro Sekunde 1 HP abgezogen. So werden dem Spieler maximal 2 HP pro Sekunde abgezogen, bis er Items einsetzt, um dies zu verhindern.

#### Inventar

![](https://survisland.de/assets/inventart.png)   
*Das Inventar*

Der Spieler besitzt ein Inventar mit einem Maximalgewicht, das nicht überschritten werden kann. Dies haben wir mithilfe eines ActorComponents realisiert, der zu dem Character-Blueprints des Spielers hinzugefügt wird. Das Gewichtslimit wird in Grau als eigene Statusleiste angezeigt.

Die Items sind so lange sie in der Map sind ein eigener Actor mit einem Würfel als Modell. Die Farbe wird mit einer dynamischen Material-Instanz generiert, sodass jedes Item trotz des gleichen Modells auf Distanz schon erkannt werden kann.

|Item|Farbe|
|----|-----|
|Bandage|Rot|
|Wasser|Blau|
|Essen|Braun|

Darüber hinaus passen die Farben zu denen der Statusleiste des Spielers.

![](https://survisland.de/assets/ZxtFOjAHY0.gif?vid=4)   
*Alle Items nebeneinander*

Um das Modell der Items befinden sich zwei unterschiedlich große Boxen. Die größere hat ein OnOverlap-Event, bei dem wir überprüfen, ob sich der Spieler innerhalb dieser Box befindet. Erst dann überprüfen wir ob der Spieler auch das Item bzw. die kleinere Box anschaut.
Da wird diese Sichtkontrolle über das Event Tick machen, also jeden Frame aufrufen, haben wir die Bedingung der Nähe gesetzt.
Bei etwa 120 Items auf ~1km² der eigentlichen bespielbaren Fläche ist die Wahrscheinlichkeit sehr hoch, dass sich der Spieler nur in der Nähe eines Items, wenn überhaupt, befindet. Bei einer Framerate von 30 FPS haben wir so 3570 unnötige Funktionsaufrufe gespart. Bei 60 FPS sind es etwa 7140.

![](https://survisland.de/assets/Uploads/itemboxen.png?vid=3)    
*Ein Item mit sichtbaren Kollisionsboxen*

Die Kontrolle, ob der Spieler ein Item anschaut, ist dabei auch sehr simpel:
Wir nehmen den Richtungsvektor der Kamera des Spielers bzw. ein Vielfaches dieses Vektors und überprüfen, ob er die kleinere Box schneidet. Wenn dem so ist, erlauben wir dem Spieler die Funktion fürs Aufsammeln aufzurufen.

## KI-Gegner / NPC

![](https://survisland.de/assets/Uploads/ai.png?vid=3)
*Zwei NPCs*

Bei unserer KI unterscheiden wir zwischen den Stadt-NPCs und den Wald NPCs:
- Stadt-Typ 1 steht dauerhaft innerhalb von Gebäuden
- Stadt-Typ 2 geht zwischen zufälligen Punkten einer Stadt hin und her
- Wald-Typ wandert hauptsächlich in den Wäldern bzw. auf den Straßen umher. Kann zufällig in eine Stadt oder ein Haus gelangen

Jeder NPC besteht dabei wie der Spieler aus einem Pawn, in diesem Fall auch ein Character, und einem Controller.
Jetzt handelt es sich allerdings um ein AI-Controller. Die Hauptlogik der KI wird mithilfe von den AI-Blackboards, einer Sonderform von Blueprints, festgelegt. Mit diesem Blueprint lassen sich verschiedene Zustände der KI festlegen und die Konditionen, die erfüllt sein müssen, um diese Zustände zu erreichen.

![](https://survisland.de/assets/Uploads/typ2.png?vid=3)
*Blackboard-Blueprint von Typ 2*

Die Hauptaufgabe für den KI-Typen 1 ist es, zu überprüfen, ob der Spieler sich in Sichtweite befindet. Wenn dies so ist, wird die Kondition CanSeePlayer gesetzt, sodass die KI nun in den Status der Verfolgung gelangen kann. Sie versucht jetzt den Spieler in Schussweite zubringen. Wenn dies gelingt, wird der Status zum Angriffsmodus geändert, in dem nur in einem festen Intervall auf den Spieler gefeuert wird.

![](https://survisland.de/assets/Uploads/aispawner.png?vid=3)   
*Der Spawner für Typ 2*   


Während der KI-Typ 1 noch von den Häusern selbst gespawnt wird, haben wir für Typ 2 einen Actor gebastelt, der das Spawnen übernimmt.
Damit das alles so funktioniert haben wir erst einen Actor erstellt, der CityWaypoint heißt. Die einzige relevante Variable dieses Actors ist die 'CityID'. Danach haben wir 4 Child-Klassen des CityWaypoints erstellt - für jede Stadt eine. In diesen haben wir dann die 'CityID' auf 0, 1, 2 bzw. 3 gesetzt. Anschließen haben wir an jeder Kreuzung in einer Stadt so einen CityWaypoint gesetzt.

In unserem AISpawner haben wir dann für jedes Objekt der Klasse CityWaypoint (das umfasst auch die Child-Klassen) einen neuen NPC spawnen lassen und anschließen den CityIndex im NPC auf Index des aktuellen CityWapoints gesetzt.

Jetzt können wir im NPC uns einen zufälligen CityWaypoint aussuchen, der in der Stadt liegt, in der auch der NPC gespawnt wurde. So sorgen wir dafür, dass sich immer eine hohe Anzahl an NPCs in einer Stadt befinden.

Bei Typ 3 bzw. dem Wald-Typ ist das ganze deutlich simpler: Er sucht sich einfach einen zufälligen Punkt im Radius, durch den der AI-Controller navigieren kann, und läuft dahin.

#### Wann hält ein AI-Controller einen Punkt für navigierbar?

Damit sich eine KI in einer Welt bewegen kann, muss ihr natürlich kommuniziert werden, wo sie sich bewegen darf. Das geschieht in der UnrealEngine, wie in vielen anderen Engines und Spielen auch, über ein NavMesh (Navigation-Mesh). Es ist eine Art unsichtbare Schicht, die über dem Boden des Levels liegt. Befinden sich hohe Objekte im Weg des NavMeshes, wird es um das Objekt herum generiert.
Befindet sich ein Punkt innerhalb dieses Meshes, ist er navigierbar.

Bei kleinen Maps ist das auch kein Problem: Die Berechnungen für ein kleines und statisches NavMesh gehen recht schnell. Allerdings ist unsere Map mit ihren 4km² vergleichsweise groß. Das würde für sehr lange Rechenzeiten sorgen. Darüberhinaus ist die Karte auch noch in 4 Kacheln aufgeteilt, die ggf. nicht alle parallel geladen sind. So müsste das Mesh beim Laden einer Kachel neu berechnet werden.

Deshalb verwenden wir NavigationInvokers. Die werden zum Pawn des NPCs hinzugefügt und generieren dynamisch ein NavMesh um den NPC herum.


## Kampfsystem

Obwohl Spieler und NPCs eine Waffe mit sich herumtragen, kommen diese nie zum Einsatz: Für das Kampfsystem verwenden wir Line-Traces (auch Raycasting / Raytracing), also eine einfache virtuelle Gerade zwischen zwei Punkten. Der Startpunkt ist bei uns entweder die Kamera des Spielers oder der Kopf eines NPCs. Endpunkt ist der Richtungsvektor der Kamera bzw. des Kopfes * 5000uu (UnrealUnits; 1uu = 1cm). Das ist unsere simulierte Reichweite der Waffe. Wir ziehen also bei jedem Schuss eine Gerade und schauen, ob die Gerade einen Gegener schneidet. Wenn dem so ist, wird das Damage-Event der UnrealEngine ausgelöst, das wir im Blueprint des Spielers und der NPCs implementiert haben.
Da wir keine Effekte oder ähnliches beim Schießen anzeigen, benutzen wir eine Option, die eigentlich zum Debuggen gedacht ist: Wir lassen uns die Line-Traces anzeigen. So bekommt der Spieler ein Trefferfeedback und kann auch nachvollziehen, wie er zum Beispiel von der KI getroffen wurde.

![](https://survisland.de/assets/Uploads/Qc0wibatZu.gif?vid=3)   
*Ein Kampf*   

## Weiteres

### Steuerung

|Taste|Aktion|
|-----|------|
|W|Vorwärts gehen|
|S|Rückwärts gehen|
|A|Nach Links gehen|
|D|Nach Rechts gehen|
|Leertaste|Springen|
|Strg|Ducken|
|Tab|Inventar öffnen/schließen|
|F|Item aufheben|
|Linke Maustaste|Schießen / Interaktion im Inventar|     

### Installation

*Umfasst lediglich die Installation der von uns kompilierten Versionen. Eine Anleitung zum kompilieren wird noch erstellt*

Survisland kann auf https://downloads.survisland.de/ runtergeladen werden.
Dort gibt es eine Liste mit allen Versionen und ggf. Hinweisen zu dieser Version.
Es gibt dabei an sich zwei Möglichkeiten:

- Game (Plattform)
- Patch (Plattform)

Game ist hierbei das komplette Spiel in der genannten Version und Patch ist lediglich ein .pak-Archiv mit den Änderungen eines Updates im Vergleich zur Vorgängerversion. Die Patches sind allerdings erst ab Version 0.2.0 verfügbar.

*Beispiel:*
0.1.0 Game + 0.1.1 Patch = 0.1.1 Game

![](https://survisland.de/assets/Uploads/downloads.png?vid=3)   
*Die Download-Seite*   

*Tipp:* Mit https://downloads.survisland.de/latest/plattform kann stets die aktuellste Version des Spiels runtergeladen werden. 'plattform' muss hier mit dem passenden Kürzel ersetzt werden (s. Tabelle unten).

Der Download umfasst ein .zip-Archiv mit dem Namen 'Survisland-Version-Plattform'. Das kann einfach entpackt werden (z.B. mit dem Windows-Explorer). Im Ordner 'Survisland' befindet sich die 'Survisland.exe', über die das Spiel gestartet werden kann.

![](https://survisland.de/assets/Uploads/folder.png?vid=3)   
*Survisland.exe im Windows-Explorer*   
   
#### Plattformen

Derzeit ist Survisland nur für Windows verfügbar.

|Kürzel|Plattform|
|------|---------|
|win64|Windows (64-Bit)|
|win32|Windows (32-Bit)|

Versionen für Linux und Android werden wir nach der Abgabe noch hinzufügen (oder im zweiten Halbjahr ;))

### Updates / Patches

Der Download eines Patches umfasst ebenfalls ein .zip-Archiv. Der Name ist dabei lediglich 'Survisland-Version'. Im Archiv ist nur eine .pak-Datei, die in den Ordner 'Survisland\Content\Paks' entpackt werden kann.

## Das fertige Spiel

Zum Schluss noch ein paar Impressionen aus dem Spiel

![](https://survisland.de/assets/Survisland_0DFuZQsbeR.png?vid=4)
![](https://survisland.de/assets/Survisland_2FgTxHMUgK.png?vid=4)
![](https://survisland.de/assets/Survisland_8lQ2u7VMdm.png?vid=4)
![](https://survisland.de/assets/Survisland_cD39CEDOOY.png?vid=4)
![](https://survisland.de/assets/Survisland_NYQVETORwK.png?vid=4)