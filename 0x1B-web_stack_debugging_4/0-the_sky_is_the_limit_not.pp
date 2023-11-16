# Fix the stack so that there is not failed requests, by
#  increases the amount of traffic an Nginx server can handle


# Increase the ULIMIT of the default file.
exec { 'change nginx limit':
    command  => 'sudo sed -i "s/15/4096/g" /etc/default/nginx; sudo service nginx restart',
    provider => shell,
}}
