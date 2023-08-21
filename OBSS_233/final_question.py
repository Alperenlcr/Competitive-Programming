from Crypto.Cipher import AES
import base64
import os, re

def decrypt(file_name, key):
    with open(file_name, 'rb') as fo:
        content = fo.read()
    cryptor = AES.new(key, AES.MODE_CBC, os.urandom(16))
#    content += (len(content) % 4) * '='
    content = base64.urlsafe_b64decode(content)
    decrypted = cryptor.decrypt(content)
    return decrypted
    # try:
    #     return re.compile('[\\x00-\\x08\\x0b-\\x0c\\x0e-\\x1f\n\r\t]').sub('', decrypted.decode())
    # except Exception:
    #     raise ValueError("inputted value can not be decrypted.")

key = b'pBaGQuYvArwCIbTiqgVJaavtvlDfDACf'

text = decrypt('sample_input_encrypted.txt', key)

pages = text.split(b'~@~')
temp = []

for x in pages:
    temp.append(x.split(b'\n'))
final =[]
for p in temp:
    final.append([])
    for l in p:
        if l != b'':
            final[-1].append(l)
    if final[-1] == []:
        final.pop()
print(final)
for pages in final:
    for line in pages:
        if re.findall(r'[F][a-zA-Z]+[I][0-9]*[N][^a-zA-Z\d\s:]{,5}[D].*\b[0-9]+[x][0-9]+', str(line)) != []:
            a,b = re.findall(r'\b[0-9]+[x][0-9]+', str(line))[0].split('x')
            # print(f'page:{a} line{b}')
            try:
                print(''.join(filter(lambda i: i.isdigit(), str(final[int(a)-1][int(b)-1]))),end='')
            except IndexError:
                pass
#decrypt_file('sample_input_encrypted.txt', key)