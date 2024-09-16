Voici la correction des fautes :

# Pokémon version IS

## Règles du jeu :
Le joueur commence sa partie en choisissant son équipe parmi 20 Pokémon. Il part ensuite à l'aventure pour combattre et 
capturer des Pokémon. S'il remporte 3 combats, c'est gagné ; si tous ses Pokémon sont mis KO, le joueur perd. Pour 
prolonger le plaisir, le joueur a l'opportunité de capturer les Pokémon s'il parvient à faire descendre les points de 
vie de son adversaire en dessous du tiers de sa vie initiale.

## Astuce :
Dans la partie "Exploration Sans Danger", il faut appuyer sur "Entrée" pour faire défiler le texte suivant.

## Erreur non résolue :
Le code plante au moment de détruire les différents objets. Il semblerait qu'au moment de l'implémentation de la 
fonction de capture, un Pokémon soit créé sur la pile et non alloué dynamiquement, mais je n'ai pas réussi à déboguer 
l'erreur. Elle n'apparaît qu'après la fin du jeu, donc elle ne gêne pas fondamentalement le fonctionnement de la machine 
à états.