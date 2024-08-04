# Arduino DMX Switch

This code will map DMX channels to Arduino pins.
You can use this to create cheap DMX controller switch.

For this need DMX shield and probably some AC switches. 

Change `PIN_MAPPER` To change PIN-Channel mapping and behavior.

# CAD Designs
This project is designed with two cases to keep your arduino safe. Part list below.
![image](https://github.com/user-attachments/assets/6538d5a9-1239-4c0d-98a0-97bfce31393d)
![image](https://github.com/user-attachments/assets/5c7d155b-fa6a-4f01-bc89-de157f478561)

You will need to add metal threads insterts to holes and screw lead with bottom part. 

# Relays
I recommend using SSR Relays for this project. They are quite robust and can if used properly can survive years.
Just make sure that your load is not inductive (For example electric motor) or you will need to add proper filters on AC side (snubber circuit)
You can power SSR's directly from arduino pins. 
![image](https://github.com/user-attachments/assets/be564e50-7866-452b-be32-c2835fd633e2)

# Sockets
You need to buy Blue 16A 220-240V 2P+E Waterproof IP54 two-poles sockets. 
![image](https://github.com/user-attachments/assets/ce011700-5d8e-4eea-8620-74b8a1b37649)

# Arduino power supply
You can use any 5V power supply and wire it up to AC circuit. (IMO best way is to glue it to SSR casing)
If you want to use wireless DMX you can use this power supply to power wireless DMX. 

# Screws

# Wiring
