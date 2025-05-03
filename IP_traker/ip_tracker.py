from requests import get
import re

# API call without IP to take your own data


def getOwnData():
    return get('https://ipapi.co/json/').json()

# API call with IP to take the IP data


def getDataByIP(ip):
    return get('https://ipapi.co/'+ip+'/json/').json()

# Show all the data from the API


def printData(data):
    print("\nIP:", data["ip"])
    print("Network:", data["network"])
    print("Continent:", data["continent_code"])
    print("Country:", data["country_name"])
    print("Region:", data["region"])
    print("City:", data["city"])
    print("Postal Code:", data["postal"])
    print("Latitude:", data["latitude"])
    print("Longitude:", data["longitude"])
    print("Timezone:", data["timezone"])
    print("Calling code:", data["country_calling_code"])
    print("Currency:", data["currency_name"])
    print("ASN:", data["asn"])
    print("Organitation:", data["org"])

# Menu to pick what you want to do


def menu():
    while True:
        print("\nIP TRACKER \n")
        print("1: Track own IP")
        print("2: Track someone IP")
        print("3: Finish \n")
        option = input("")

        if option == "1":
            printData(getOwnData())
        elif option == "2":
            ip = input("IP to track: ")
            if re.match(r"^((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\.){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])$", ip):
                printData(getDataByIP(ip))
            else:
                print(
                    "\nBad IP, they are form by 4 numbers separated by points no number bigger than 255 (example 217.34.123.89)")
        else:
            break


menu()
