# ROBOT

Bonjour, si vous souhaitez faire focntionner ce programme sous linux, il ne faut pas tenir compte du prog et prog.exe, il faut compiler une deuxime fois sous linux avec g++ en faisant  g++ -std=c++14 *.cpp -o prog

Si vous souhaitez utiliser ce programme sous Windows, téléchargez le dossier, mais NE PAS cliquer sur le prog.exe. Il faut l'executer avec Powershell. Ouvrez juste powershell dans le dossier et faites ./prog

Le .exe est là car il est généré automatiquement, mais ayant utilisé des exit() en cas de defaite lors du jeu, si vous cliquez sur le .exe et que vous perdez, vous ne verrez pas le texte qui s'affiche à la fin, la fenêtre qui était ouverte fermera avant. Contrairement au terminal
