import requests
from bs4 import BeautifulSoup as bs
from urllib.parse import urlparse

class Solve():
    def __init__(self, start_link):
        self.index_values = {}
        self.ignore_values = {"", "/"}
        self.domain = urlparse(start_link).netloc
        self.queue = [start_link]
        self.iterate_links()
        self.output()


    def iterate_links(self):
        visited = [self.queue[0]]
        self.find_values(self.queue[0])
        while len(self.queue) != 0:
            new_links = self.find_links(self.queue.pop(0))
            for link in new_links:
                if link not in visited:
                    visited.append(link)
                    self.queue.append(link)
                    self.find_values(link)


    def find_links(self, curr_link):
        html = requests.get(curr_link).text
        soup = bs(html, 'html.parser')
        # Find links and filter
        return list(set([a["href"] for a in soup.find_all("a", href=self.desired_links) if self.domain == urlparse(a["href"]).netloc]))


    def find_values(self, link):
        html = requests.get(link).text
        soup=bs(html, 'html.parser')
        all = soup.find_all()
        for temp in all:
            index = temp.get('x-data-index')
            if index != None:
                self.index_values[int(index)] = temp.get('x-data-value')
                # if index in self.index_values:
                #     print(self.index_values[index], temp.get('x-data-value'))


    def output(self):
        liste = sorted(list(self.index_values.items()))
        output = ""
        for element in liste:
            output += element[1]
        print(output)


    def desired_links(self, href):
        # ignore if href is not set
        if not href:
            return False

        # ignore if it is just a link to the same page
        if href.startswith("#"):
            return False

        # skip ignored values
        if href in self.ignore_values:
            return False

        return True


"""
https://cm2023.obss.io/2165506a-18f1-4322-a260-bd8b6dc2240e?lang=EN
https://cm2023.obss.io/041ad879-a3db-474d-968c-a06fae9c2023?lang=EN
"""
start_link = "https://cm2023.obss.io/041ad879-a3db-474d-968c-a06fae9c2023?lang=EN"
S = Solve(start_link)

# get html for start link
# find all links included but in the same domain and no web site links
# do it recursively
# in every html find values and append them to a list
# print list in order