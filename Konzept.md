# Arbeitstitel: 'Survisland'

Unser Konzept in der Form wie wir es zu Beginn geschrieben haben.
Einige Erläuterungen sind hier zu finden: https://gitlab.com/f2p-entertainment/other/informatik-projekte/informatik-projekt-1/wikis/Konzepterkl%C3%A4rung

## Das Projekt

Survival-Game auf einer Insel. Das Spiel soll auf der UnrealEngine 4 basieren und in C++ und Blueprints erstellt werden.


### Die Spielwelt

Eine Insel, die zu Beginn nicht verlassen werden kann. Diese Insel hat eine in Form von NPCs eine Bedrohung für den Spieler.

Zu Spielbeginn werden sammelbare Gegenstände gespawnt. Diese werden nach Ablauf eines Timers neu gespawnt. Die genauen Positionen sind zufällig.

Auf der Insel gibt es zwei Arten von Regionen:

1. Bebaute Gegenden. NPCs spawnen mit höherer Wahrscheinlichkeit.
2. Wald. Straßen führen durch den Wald und verbinden die bebauten Gegenden. NPCs spawnen seltener


### Spielmechaniken

Grundlegend hat der Spieler einen begrenzent Healthpool

#### Healthpool

Mit Objekten wie Bandagen kann der Healthpool wieder aufgefüllt werden.


#### Bedürfnissystem

Der Spieler muss sich auf die Suche nach Nahrung und Wasser begeben.


#### Kampfsystem

Auf der Insel können Waffen gefunden werden, die es dem Spieler erlauben sich die NPCs zu verteidigen.


#### Inventarsystem

Der Spieler hat ein Inventar mit einem maximalen Gewichtswert. Ist dieses Limit ausgeschöpft, kann nichts mehr aufgenommen werden.

##### Ausrüstung

Im Inventar kann der Spieler seine Ausrüstung verwalten.   
Es können Rucksäcke gefunden werden, um das Gewichtslimit zu vergrößern.   
Außerdem kann Bekleidung / Rüstung gefunden werden, die die Widerstandsfähigkeit des Spielers erhöhen.   


### 'Nice-to-have': 

#### Alternative Fortbewegung

Fahrzeuge mit begrenzten Spritreserven könnten zufällig gespawnt werden, die dem Spieler erlauben sich schneller fortzubewegen.

#### Inventar-Managament

Der Platz im Inventar wird mit einem Gitternetz dargestellt und die Objekte haben eine gewisse Größe, sodass das Inventarsystem mehr Tiefe bekommt.

#### Crafting

Mit den gesammelten Items und Rohstoffen kann der Spieler neue Objekte herstellen, die ihm einen Vorteil beim Überleben geben.

#### Story

Hinweise auf die Geschehnisse vor Ankunft des Spielern, die auf der Insel verteilt sind.

#### Spielziel

Der Spieler könnte mithilfe der gesammelten Resourcen Objekte bauen, die ihm erlauben die Insel zu verlassen.