# Projet Cub3D - École 42

## Description
Cub3D est un projet de l'École 42 qui consiste à créer un moteur de rendu 3D simple en utilisant la technique du raycasting. Inspiré du célèbre jeu Wolfenstein 3D, ce projet permet de comprendre les bases de la programmation graphique et de la création d'environnements 3D.

## Objectifs
- Implémenter un algorithme de raycasting
- Créer un moteur de rendu 3D basique
- Gérer les mouvements du joueur et les collisions
- Charger et afficher des textures
- Parser une carte à partir d'un fichier de configuration

## Fonctionnalités
- Rendu 3D en temps réel d'un labyrinthe
- Mouvement fluide dans quatre directions
- Rotation de la caméra
- Textures différentes pour les murs
- Gestion des collisions
- Minimap (optionnel)

## Compétences développées
- Programmation graphique
- Optimisation des performances
- Gestion des événements et des inputs utilisateur
- Mathématiques appliquées (trigonométrie, vecteurs)
- Parsing de fichiers

## Installation et utilisation
1. Clonez ce dépôt :
   ```
   git clone https://github.com/votre-username/cub3d.git
   ```
2. Naviguez dans le dossier du projet :
   ```
   cd cub3d
   ```
3. Compilez le projet :
   ```
   make
   ```
4. Lancez le programme avec une carte :
   ```
   ./cub3D maps/map.cub
   ```

## Contrôles
- Flèches directionnelles : Déplacement
- A/D : Rotation de la caméra
- ESC : Quitter le jeu

## Format de la carte
Le fichier de carte (.cub) doit respecter le format suivant :
```
R 1920 1080
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
S ./path_to_the_sprite_texture
F 220,100,0
C 225,30,0

1111111111111111111111111
1000000000110000000000001
1011000001110000002000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10002000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```
