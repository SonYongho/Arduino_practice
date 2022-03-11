# 쟝고로 만든 개인 api

import requests

url = 'http://127.0.0.1:8000/api/greet?name=yukina&age=17'

res = requests.get(url)
print(res.json())