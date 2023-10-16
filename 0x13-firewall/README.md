# :book: 0x13. Firewall

![330px-Firewall.png](https://static.tutorialandexample.com/cyber-security/firewall1.png)

*An illustration of a network-based firewall within a network, courtesy of wikipedia*

A firewall is a network security system that monitors and controls incoming and outgoing network traffic based on predetermined security rules.It typically establishes a barrier between a trusted network and an untrusted network, such as the Internet.

## Firewall types
### 1. Network-based
Positioned between two or more networks, typically between the LAN and WAN. They are either;
 - a software appliance running on general-purpose hardware.
 - a hardware appliance running on special-purpose hardware.
 - a virtual appliance running on a virtual host controlled by a hypervisor.

### 2. host-based system firewalls
Deployed directly on the host itself to control network traffic or other computing resources. Can be;
 - a daemon or service as a part of the operating system.
 - an agent application for protection.

## ufw firewall
A program for managing a netfilter firewall designed to be easy to use. It uses a command-line interface consisting of a small number of simple commands, and uses iptables for configuration.


```bash
# Check ufw status
sudo ufw status

# Show added rules
sudo ufw show added

# Enable ufw
sudo ufw enable

# Restart ufw
sudo service ufw restart

# Disable ufw
sudo ufw disable

# Reset ufw
sudo ufw reset

# Edit before rules
sudo vi /etc/ufw/before.rules
```

# :computer: Tasks
## [0. Block all incoming traffic but](0-block_all_incoming_traffic_but)
Install firewall and set up rules; block all incoming traffic except TCP ports 22, 443 and 80 in web-01 server.

```bash
# Allow port 22 for ssh
sudo ufw allow ssh

# Allow port 443 for https/ssl
sudo ufw allow https

# Allow port 80 for http
sudo ufw allow http

# Enable ufw
sudo ufw enable
```

## [1. Port forwarding ](100-port_forwarding)
Configure web-01 so that its firewall redirects port 8080/TCP to port 80/TCP.

```bash
# Redirect incoming connections to port 8080 to port 80 set rule in /etc/ufw/before.rules add the port redirection rule
*nat
:PREROUTING ACCEPT [0:0]
-A PREROUTING -p tcp --dport 8080 -j REDIRECT --to-port 80

```

```bash
# TODO: Write a shell or python test.
# Check port 80
curl -sI web-01.msofteng.tech:80

# Check port 8080 forwarding to port 80
curl -sI web-01.msofteng.tech:8080
curl -sI 3.85.222.47:8080
```

# :books: References
1. [Firewall (computing) Wikipedia](https://en.wikipedia.org/wiki/Firewall_%28computing%29)
2. [Uncomplicated Firewall](https://en.wikipedia.org/wiki/Uncomplicated_Firewall)
3. [How To Set Up a Firewall with UFW on Ubuntu 14.04](https://www.digitalocean.com/community/tutorials/how-to-set-up-a-firewall-with-ufw-on-ubuntu-14-04)
4. [How to set up UFW port forwarding](https://bobcares.com/blog/ufw-port-forwarding/)


# :man: Author and Credits.
This project was done by [SE. LAHBARI Ismail](https://github.com/ismail-la). Feel free to get intouch with me;

:email: Email: [lahbariismail@gmail.com](lahbariismail@gmail.com)

:thumbsup: A lot of thanks to [ALX-Africa Software Engineering](https://www.alxafrica.com/) program for the project requirements.


