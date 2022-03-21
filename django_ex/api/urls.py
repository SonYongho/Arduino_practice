from django.urls import path
from api.views import greet, sensor_list, upload_record

urlpatterns = [
    path('greet/', greet),
    path('sensor_list/', sensor_list),
    path('upload_record/', upload_record),
]
