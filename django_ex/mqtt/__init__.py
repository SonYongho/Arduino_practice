#-*- coding:utf-8 -*-

import paho.mqtt.client as mqtt


def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+ str(rc))
    if rc == 0:
        client.subscribe("iot/#")

    else:
        print('연결 실패 : ', rc)

def on_message(client, userdata, msg):
    from .models import Sensors

    value = float(msg.payload.decode())
    (_, user, place, sensor) = msg.topic.split('/')
    # 모델을 사용해서 저장
    s = Sensors(user=user, place=place, sensor=sensor)
    s.save()
    
client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

try :
    client.connect("localhost")
    client.loop_start() # 새로운 스레드 실행 --> daemon 스레드 -> main 스레드 종료 시에 강제 종료됨

except Exception as err:
    print('에러 : %s'%err)