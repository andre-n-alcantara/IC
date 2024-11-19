from urllib.request import urlopen
from bs4 import BeautifulSoup
import re
import os

def get_text(base_url, href):
  html = urlopen(base_url+href)
  pattern = r"[^/]+/$"
  file_name = re.search(pattern, href).group()
  file_name = file_name[:len(file_name)-1]

  pattern = r"/[0-9]+/"
  edicao = re.search(pattern, href).group()
  edicao = edicao[1:len(edicao)-1]

  bs = BeautifulSoup(html, 'html.parser')
  content = bs.select('form ~ *')
  text = []
  for it in content:
    text.append(it.text)
  text = ' '.join(text)

  return file_name,edicao,text

def save_txt(root, file_name, edicao):
  path = os.path.join(root,'OBI'+edicao)
  if file_name not in os.listdir(path):
    print(f'Erro! {file_name},{edicao} nao existe.')
  path = os.path.join(path, file_name)
  os.makedirs(path, exist_ok=True)
  path = os.path.join(path, file_name+'.txt')
  with open(path,'w',encoding='utf-8') as f:
    f.write(text)

niveis = ['pj','p1','p2','pu']
for nivel in niveis:
  html = urlopen("https://olimpiada.ic.unicamp.br/pratique/"+nivel)
  bs = BeautifulSoup(html, 'html.parser')
  anchors = bs.select('li.atask a')
  hrefs=[]
  for anchor in anchors:
    hrefs.append(anchor.get('href'))
  root = './OBI'
  base_url="https://olimpiada.ic.unicamp.br"
  for href in hrefs:
    file_name,edicao,text = get_text(base_url,href)
    save_txt(root, file_name, edicao)




