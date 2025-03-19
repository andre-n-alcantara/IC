#SCRAPE DO TXT DE TODAS AS QUESTOES EM  https://olimpiada.ic.unicamp.br/pratique/ 
from urllib.request import urlopen
from bs4 import BeautifulSoup
import re
import os
import requests
import json
def get_text(base_url, href, contain_image):
    html = urlopen(base_url+href)
    splitted = href.split('/')
    nivel = splitted[2]
    edicao = splitted[3]
    fase = splitted[4]
    file_name = splitted[5]
    
    bs = BeautifulSoup(html, 'html.parser')
    form_element = bs.find('form')
    parent_element = form_element.find_parent() 
    form_element.decompose()  # ENUNCIADO DA QUESTAO ESTA JUNTO COM O FORM (DESCOBERTO POR INSPECAO DA PAGINA)
    if parent_element.find('img') is not None:
        contain_image.append(href)
    return edicao, nivel, fase, file_name, parent_element.text

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

def get_passadas(): # AS QUESTOES NAO DISPONIVEIS NO "PRATIQUE" https://olimpiada.ic.unicamp.br/passadas/ NAO TEM TEXTO EM HTML, APENAS ARQUIVOS PDF PARA SEREM BAIXADOS POR download_file()
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
    return anchors

def get_pratique():
    contain_image = []
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
            file_name,edicao,fase,text = get_text(base_url,href,contain_image)
            save_txt(root, file_name, edicao, fase, nivel, text)

def get_pratique2():
    contain_image = []
    hrefs= []
    with open('pratique.json', 'r', encoding='utf-8') as f:
        hrefs = json.load(f)
    base_url="https://olimpiada.ic.unicamp.br"
    
    for href in hrefs:
        print(href)
        edicao, nivel, fase, file_name, text = get_text(base_url,href,contain_image)
        with open(os.path.join('./pratique',f'{edicao}-{nivel}-{fase}-{file_name}.txt'),'w',encoding='utf-8') as f:
            f.write(text)
        
    with open('contain_image.json', 'w', encoding='utf-8') as f:
        json.dump(contain_image, f, ensure_ascii=False, indent=4)

get_pratique2()
    


