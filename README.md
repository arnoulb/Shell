## 42sh - Projet scolaire

Réalisation d'un interpréteur de commandes UNIX qui permet d'accéder aux fonctions du système d'exploitation

**Fonctionnement :**
```
Make
./42sh
```

**Fonctions implémentées :**
- Gestion des variables d'environnement ($PATH pour l'execution des binaires)
- Gestion des erreurs et des valeurs de retour ($? et Segmentation fault)
- Redirection des flux d'entrée et de sortie (simples : '<', '>' et doubles : '<<', '>>')
- Gestion des pipes ('|')
- Implémentation des builtins (cd, echo, exit, setenv et unsetenv)
- Gestion des séparateur : ';', '&&' et '||'
