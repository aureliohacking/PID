# -*- coding: utf-8 -*-
"""
Editor de Spyder

Este es un archivo temporal.
"""


import pandas as pd
import numpy as np
from sklearn.neural_network import MLPRegressor

datos=pd.read_excel("datos.xlsx")


y=datos["valor"]
x=datos["segundos"]

X=x[:,np.newaxis]
a=float(input("Digite el valor del tiempo a predecir: "))

while True:
    from sklearn.model_selection import train_test_split
    X_train, X_test, y_train, y_test = train_test_split(X, y)
    		
    mlr=MLPRegressor(solver='lbfgs',alpha=1e-5,hidden_layer_sizes=(3,3),random_state=1)
    mlr.fit(X_train,y_train)
    print(mlr.score(X_train,y_train))
    if mlr.score(X_train,y_train) > 0.95 :
        break
print("prediccion es : ",mlr.predict([[a]]))
