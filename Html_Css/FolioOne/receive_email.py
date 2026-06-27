import smtplib
from email.message import EmailMessage
from dotenv import load_dotenv
import os

load_dotenv()

MY_EMAIL = os.getenv("MY_EMAIL")
APP_PASSWORD = os.getenv("APP_PASSWORD")
SEND_EMAIL= os.getenv("SEND_EMAIL")


def receive_contact_form(name, email, subject, message):

    msg = EmailMessage()

    msg["Subject"] = f"Portfolio Contact: {subject}"
    msg["From"] = MY_EMAIL
    msg["To"] = SEND_EMAIL

    msg.set_content(
        f"""
            Name: {name}
            Email: {email}
            
            Message:
            {message}
        """
    )

    with smtplib.SMTP_SSL("smtp.gmail.com", 465) as smtp:
        smtp.login(MY_EMAIL, APP_PASSWORD)
        smtp.send_message(msg)