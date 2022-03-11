from requests import get
def download(url, file_name):
  with open(file_name, "wb") as file:
    response = get(url)
    file.write(response.content) # get request # write to file
if __name__ == '__main__':
    url = "https://cdn.arduino.cc/homepage/static/media/arduino-UNO.bcc69bde.png"
    download(url,"arduino.png")