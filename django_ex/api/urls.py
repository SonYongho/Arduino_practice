from django.urls import path
from api.views import greet, sensor_list

urlpatterns = [
    path('greet/', greet),
    path('sensor_list', sensor_list)
]
