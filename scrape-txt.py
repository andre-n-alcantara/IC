#SCRAPE DO TXT DE TODAS AS QUESTOES EM  https://olimpiada.ic.unicamp.br/pratique/ 
from urllib.request import urlopen
from bs4 import BeautifulSoup
import re
import os
import requests

def get_text(base_url, href):
  html = urlopen(base_url+href)
  pattern = r"[^/]+/$"
  file_name = re.search(pattern, href).group()
  file_name = file_name[:len(file_name)-1]

  pattern = r"/[0-9]+/"
  edicao = re.search(pattern, href).group()
  edicao = edicao[1:len(edicao)-1]

  pattern = r"/f[0-9]/"
  fase = re.search(pattern, href).group()
  fase = fase[1:len(fase)-1]
  
  bs = BeautifulSoup(html, 'html.parser')
  form_element = bs.find('form')
  parent_element = form_element.find_parent()
  form_element.decompose()
  
  return file_name,edicao,fase,parent_element.text

def save_txt(root, file_name, edicao, fase, nivel, text):
  path = os.path.join(root,'OBI'+edicao,file_name)
  if not os.path.exists(path):
    print(f'Erro! {file_name} nao existe.')
  os.makedirs(path, exist_ok=True)
  path = os.path.join(path, nivel+'-'+fase+'-'+file_name+'.txt')
  with open(path,'w',encoding='utf-8') as f:
    f.write(text)

def download_file(url, save_dir):
  os.makedirs(save_dir, exist_ok=True)
  response = requests.get(url)
  if response.status_code == 200:
    save_path = os.path.join(save_dir, '')
    with open(save_path, 'wb') as file:
      file.write(response.content)
      print(f"Downloaded: {save_path}")
  else:
    print(f"Failed to download: {url}")

def get_passadas():
  base_url="https://olimpiada.ic.unicamp.br"
  html = urlopen(base_url+"/passadas/")
  bs = BeautifulSoup(html, 'html.parser')
  anchors = bs.select('.inner-page a')
  hrefs=[]
  for anchor in anchors:
    hrefs.append(anchor.get('href'))
  for href in hrefs:
    html = urlopen(base_url+href)
    bs = BeautifulSoup(html, 'html.parser')
    anchors = []
    for anchor in bs.select('a[href*="passadas"]'):
      href_att = anchor.get('href')
      if 'fase' in href_att and 'programacao' in href_att and 'merito' not in href_att:
        anchors.append(href_att)
    anchors

def get_pratique():
  base_url="https://olimpiada.ic.unicamp.br"
  niveis = ['pj','p1','p2','pu']
  for nivel in niveis:
    print(nivel)
    html = urlopen(base_url+"/pratique/"+nivel)
    bs = BeautifulSoup(html, 'html.parser')
    anchors = bs.select('li.atask a')
    hrefs=[]
    for anchor in anchors:
      hrefs.append(anchor.get('href'))
    root = './OBI'
    for href in hrefs:
      print(href)
      file_name,edicao,fase,text = get_text(base_url,href,nivel)
      save_txt(root, file_name, edicao, fase, nivel, text)



