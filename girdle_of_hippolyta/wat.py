import smtplib
import getpass
from email.MIMEMultipart import MIMEMultipart
from email.MIMEText import MIMEText
from email.MIMEBase import MIMEBase
from email import encoders

BOOL = {'TRUE' : ['Y', 'YES', 'TRUE'], 'FALSE' : ['N', 'NO', 'FALSE']}
def search(dic, search_for):
	for key in dic:
		for val in dic[key]:
			if search_for in val:	return key
	return None

faddr = raw_input("What gmail account would you like to send from: ") + '@gmail.com'
pword = getpass.getpass(prompt ="Password please: ")
taddr = raw_input("Who would you like to send an email to: ")

msg = MIMEMultipart()
msg['From'] = faddr
msg['To'] = taddr
msg['Subject'] = raw_input("What is your subject line: ")
msg.attach(MIMEText(raw_input("What would you like the body to contain?\n"), 'plain'))

if search(BOOL, raw_input("Do you want an attachment? ").upper()) == 'TRUE':
	fname = raw_input("What is the file name and extension: ")
	attachment = open("/nfs/2016/s/sjones/Downloads/wat.jpeg", "rb")
	aprt = MIMEBase('application', 'octet-stream')
	aprt.set_payload((attachment).read())
	encoders.encode_base64(aprt)
	aprt.add_header('Content-Disposition', "attachment; filename= %s" % fname)
	msg.attach(aprt)
else:
	print '\n'

server = smtplib.SMTP('smtp.gmail.com', 587)
server.starttls()
server.login(faddr, pword)
mail = msg.as_string()
server.sendmail(faddr, taddr, mail)
server.quit()
