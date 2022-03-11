from django.db import models

# Create your models here.
class Sensors(models.Model):
    user = models.CharField(max_length=20)
    place = models.CharField(max_length=20)
    sensor = models.CharField(max_length=20)
    value = models.CharField(max_length=20)
    reg_date = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return f'iot/{self.user}/{self.place}/{self.sensor} {self.value}'