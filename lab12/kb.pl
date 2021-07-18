mother(ron,tracy).
mother(shubh,tracy).
mother(tracy,nancy).
grandma(X,Y):-mother(X,Z),mother(Z,Y).
