from django.shortcuts import render
from django.http import JsonResponse
from mqtt.models import Sensors
from django.views.decorators.csrf import csrf_exempt

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

@csrf_exempt
def upload_record(request):
    # request.GET.get('file_name') --> get으로 보낸 경우
     
    file_name = request.POST.get('file_name') # post로 보낸 경우(라즈베리의 upload.py)
    
    print(file_name)

    # 업로드된 파일은 request.FILES에 있다
    f = request.FILES.get('video') # open된 업로드 파일(임시 파일)의 파일 객체
    file_path = f'media/record/{file_name}'
    with open(file_path, 'wb') as dest: # with 문을 벗어날 때 자동으로 close
        # data = f.read() # 파일의 전체 내용을 읽어서 리턴(오류 자주 발생)
        for data in f.chunks(): # chunks : 데이터를 조금씩 읽어서 넣어줄 때 사용
            dest.write(data)

    return JsonResponse({'result': 'success'})