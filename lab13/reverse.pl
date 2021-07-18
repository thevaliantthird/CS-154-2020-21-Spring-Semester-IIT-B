rev([X],[X]).
rev([A|L],X):-rev(L,Y), append(Y,[A],X).
