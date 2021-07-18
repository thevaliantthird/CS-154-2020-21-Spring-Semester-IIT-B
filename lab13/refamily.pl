child(sally,tom).

child(uma,sally).

child(rama,dasharath).

child(lava,rama).

child(kusha,rama).
child(arjuna,pandu).
child(pandu,vichitravirya).
child(vichitravirya,shantanu).
child(abhimanyu,arjuna).
child(parikshit,abhimanyu).
child(janmejay,parikshit).
wife(iravati,parikshit).
wife(satyavati,shantanu).
wife(subhadra,arjuna).
wife(ambalika,vichitravirya).
wife(kunti,pandu).
wife(utttara,abhimanyu).
wife(sumitra, dasharath).

grandchild(X,Y):-child(X,Z),child(Z,Y).

grandparent(X,Y):-grandchild(Y,X).

grandmother(X,Y):-grandparent(Z,Y),wife(X,Z).


grandfather(X,Y):-(grandparent(Y,X),wife(_,Y)) ; (grandparent(Z,X),wife(Z,Y)).
