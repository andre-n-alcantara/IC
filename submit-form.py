import requests
from urllib.request import urlopen
from bs4 import BeautifulSoup

html = urlopen('https://olimpiada.ic.unicamp.br/pratique/ps/2021/f1/baralho/')
bs = BeautifulSoup(html, 'html.parser')
form_elem = bs.find('form')
form_data = {}
#select
select_elem = form_elem.find('select')
selected_option = None
for option in select_elem.find_all('option'):
    option_value = option.get('value')
    if 'g++' in option_value or 'C++' in option_value:
        selected_option = option_value
        break
if selected_option:
    form_data[select_elem.get('name')] = selected_option

file_path = ''
action_url = form_elem.get('action')
with open(file_path, 'rb') as file:
    files = {'data': file}
response = requests.post(action_url, data=form_data, files=files)
print(response.text)
