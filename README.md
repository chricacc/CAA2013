CAA2013
=======

make pour compiler (le makefile est dans le dossier projetCAA)

./projetCAA pour lancer les tests de base

./projetCAA -sat <graphfilename> <outputfilename> 
pour charger le graphe contenu dans le premier fichier et obtenir une instance de SAT 
permettant d'obtenir sa couverture.
        
./projetCAA -cover <graphfilename>
pour charger le graphe contenu dans le premier fichier et obtenir une couverture.
        
./projetCAA -postSATCover <inputfilename>
Pour transformer un résultat de minisat en couverture.
