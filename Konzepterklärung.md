Hier werden einige unserer Hintergrundgedanken bezüglich unseres Konzepts sowie einiger anderer Gestaltungsentscheidungen erläutert.
Die Seite ist nach Themenbereichen des Konzepts und des Projekttagebuchs aufgeteilt.

## Spielwelt

Mit der Insel als Schauplatz des Spiels haben wir verschiedene Punkte auf einmal abdecken können:
- Eine Insel bietet eine realistische Erklärung für die räumliche Begrenzung der Spielwelt, die eine unsichtbare Wand inmitten einer Landschaft nicht bietet
- Durch die Insel wird, im Gegensatz zu weiten Landschaften, ein Gefühl der Enge erzeugt, dass die Bedrohung durch die gegnerischen NPCs größer wirken lässt
- Aufgrund der Größe der Insel, können wir leichter dafür sorgen, dass die Map bis zur Abgabe fertig wird. Sollte doch noch genug Zeit bleiben, um die Map zu vergrößern, können wir einfach eine neue Insel erstellen, die dann mit einer Brücke zur Hauptinsel verbunden wird

### Regionen

Wir haben uns für eine Aufteilung der Karte in verschiedene Regionen entschieden, um das Spiel bzw. die Spielwelt interessanter zu gestalten.

Die bebauten Regionen bieten dem Spieler auf der einen Seite eine größere Herausforderung, da dort mehr gegnerische NPCs spawnen. Auf der anderen Seite wird der Spieler zusätzlich belohnt, wenn es ihm gelingt in einer Stadt zu überleben, da in den Häusern mehr und bessere Items auf ihn warten, als in der Transferregion des Waldes.

Der Wald bzw. die Straßen, denen der Spieler folgen muss, um zur nächsten Stadt zu gelangen, sind leichter zu überstehen, aufgrund der geringeren Chance, dass dort NPCs spawnen. Auf der anderen Seite gibt es weniger Items, die der Spieler sammeln könnte.
Die Bäume erschweren es dem Spieler, durch ihre hohe Dichte und relative große Kollisionsbox, sich weit ab der Straßen zu bewegen. Das schränkt den Spieler zwar in seiner Entscheidungsfreiheit ein, erlaubt uns aber ein Zusammentreffen mit NPCs deutlich wahrscheinlicher zu Gestalten und somit das Gameplay in den Vordergrund zu rücken.

## Spielmechaniken

### Healthpool

Ein begrenzter Healthpool ist ein fester Bestandteil eines Survival-Games, da dieser die eigentliche Motivation des Spielers darstellt.

### Bedürfnissystem

Mit dem Bedürfnissystem sorgen wir dafür, dass der Spieler sich überhaupt auf die Suche nach Items machen muss.
Würde der Spieler nicht Wasser und Nahrung suchen müssen, da ein Mangel ihn Hitpoints kosten würde, dann könnte er sich einfach vor den NPCs verstecken und sich zum Sieger erklären.

### Kampfsystem

Auch das Kampfsystem ist durch die NPCs bedingt. Würden wir dem Spieler keine Möglichkeit zur Verteidigung geben, wäre das Spiel sicher auch interessant, allerdings eher im Genre der Horrorspiele anzusiedeln.

### Inventarsystem
Mit dem maximalen Gewichtswert des Inventars verhindern wir, dass der Spieler einfach alle Items, die er findet, horten kann. Ist ein Inventar voll, muss er sich für Items entscheiden und langfristig planen.

Mit der Bekleidung bzw. Rüstung, die gefunden werden kann, erlauben wir dem Spieler sich besser gegen die NPCs zu wappnen. Da diese auch vom Gewichtslimit betroffen ist und deutlich schwerer ist als normale Items, muss auch hier der Spieler stets evaluieren, ob er die geraden gefundenen Items mitnehmen kann.

## Weitere Ideen

Im Folgenden werden Gründe für die Einstufung weiterer Features als optional erklärt.
Wie und ob wir diese eingebaut haben findet sich im [Nachwort unseres Tagebuchs](https://gitlab.com/f2p-entertainment/other/informatik-projekte/informatik-projekt-1/blob/master/README.md#nachwort). 

### Alternative Fortbewegung

Die Möglichkeit zur Fortbewegung per Auto würde nur auf einer Karte Sinn ergeben, die dafür groß genug ist.

### Inventar-Management

Ein solches System per Gitternetz ist ziemlich zeitaufwendig und bringt nur in einen Teilaspekt des Spiels mehr Tiefe. Aufgrund des hohen Aufwands sollte es ggf. erst zum Schluss eingebaut werden.

### Crafting

Ein vernünftiges Crafting-System setzt eine Anzahl an Items voraus, die groß genug ist. Der Aufwand für das Crafting wäre zu groß, wenn wir nur wenige Items hätten.

### Story

Hinweise auf eine Hintergrundgeschichte sind zwar sehr einfach zu Implementieren, aber das Schreiben einer sinnvollen Handlung und das Ausarbeiten der Darstellungsmöglichkeiten kann sehr lange dauern. Deshalb planen wir dieses Feature erst ganz zum Schluss ein.

### Spielziel

Dem Spieler die Möglichkeit zu geben, die Insel zu verlassen, würde dem Spiel einen Mehrwert geben. Dies würde allerdings in der Form wie wir uns es vorstellen das Crafting-System voraussetzen, welches wir bereits als optional eingestuft haben.
Darüber hinaus würde es sinnvoll sein, das Spielziel in die Handlung mit einzubinden. Die Handlung ist allerdings ebenfalls als optionales Ziel vorgesehen.