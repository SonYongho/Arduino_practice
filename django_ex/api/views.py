from django.shortcuts import render
from django.http import JsonResponse

from mqtt.models import Sensors

# Create your views here.
def greet(request):
    name = request.GET.get('name', '이름')
    age = request.GET.get('age', 1)

    context = {
        'name' : name,
        'age' : age,
        'address' : '도쿄' 
    }

    # return render(request, 'greet.html', context)
    return JsonResponse(context) # JSON으로 응답

def sensor_list(request):
    sensor = request.GET.get('sensor')

    values = Sensors.objects.filter(sensor=sensor)
    print(values)

    return JsonResponse(values)