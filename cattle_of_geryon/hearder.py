from tornado import ioloop, httpclient, web
from urllib2 import Request, urlopen, URLError
import time
import os

i = 0

def handle_request(response):
	global i
	print(str(response.code))
	time.sleep(t)
	i -= 1
	if i == 0:
		ioloop.IOLoop.instance().stop()

n = int(raw_input("how many urls to test: "))
m = int(raw_input("how many times to test: "))
t = float(raw_input("how many seconds between: "))
if os.path.isfile('./url.txt') == True:
	os.remove('url.txt')
f = open('url.txt', 'a')
urllies = ['']
while n > 0:
	url = raw_input("what url would you like to test: ")
	req = Request(url)
	try:
		response = urlopen(req)
	except URLError, e:
		if hasattr(e, 'reason'):
			print (url + ' failed for this reason: ' + e.reason)
		elif hasattr(e, 'code'):
			print (url + ' failed because of code: ' + e.code)
	else:
		urllies.append(str(url))
		f.write(url + '\n')
	n -= 1
urllies.pop(0)
f.close()
print("test started at: " + str(time.time()))

httpc = httpclient.AsyncHTTPClient()
while m > 0:
	for url in open('url.txt'):
		print(urllies[i] + " at " + str(time.time()) + " responds with:")
		i += 1
		httpc.fetch(url.strip(), handle_request, method='HEAD')
	m -= 1
	ioloop.IOLoop.instance().start()
print("test ended at: " + str(time.time()))
