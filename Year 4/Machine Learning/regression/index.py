from sklearn.linear_model import LinearRegression
from sklearn.neighbors import KNeighborsRegressor
from sklearn.model_selection import train_test_split
from sklearn.model_selection import GridSearchCV
from sklearn import metrics

import pandas as pd
import numpy as np
import sklearn as sk

import matplotlib
import matplotlib.pyplot as plt
import seaborn as sns
# %matplotlib inline


headings = ["alcohol_by_weight", "rating", "bitterness", "nitrogen", "turbidity", "sugars",
            "degree_of_fermentation", "calorific_value", "density", "pH", "colour", "sulphites"]

# need to split into training a test data
beer_data = pd.read_csv('beer-ratings.txt', sep="\t", header=None)

# Apply the headings to data
beer_data.columns = headings

beer_data = beer_data.drop(["bitterness", "turbidity", "sugars", "degree_of_fermentation",
                            "calorific_value", "density", "pH", "sulphites"], axis=1)

train, test = train_test_split(beer_data, test_size=0.3)

x_train = train.loc[:, train.columns != 'rating'].values
y_train = train['rating']

x_test = test.loc[:, train.columns != 'rating'].values
y_test = test['rating']

knn_reg = KNeighborsRegressor(p=2)
regr = LinearRegression()

knn_reg.fit(x_train, y_train)
regr.fit(x_train, y_train)

knn_predictions = knn_reg.predict(x_test)
regr_predictions = regr.predict(x_test)

print('k-NN Results:\n')
print('MAE:\t', metrics.mean_absolute_error(y_test, knn_predictions))
print('MSE:\t', metrics.mean_squared_error(y_test, knn_predictions))
print('RMSE:\t', np.sqrt(metrics.mean_squared_error(y_test, knn_predictions)))

print('\nLinear Regression Results:\n')
print('MAE:\t', metrics.mean_absolute_error(y_test, regr_predictions))
print('MSE:\t', metrics.mean_squared_error(y_test, regr_predictions))
print('RMSE:\t', np.sqrt(metrics.mean_squared_error(y_test, regr_predictions)))
