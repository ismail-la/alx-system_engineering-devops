# Script to Install nginx web server and configure using puppet

include stdlib

# Update apt

exec { 'Update apt library':
  command => 'sudo apt update',
  path    => '/usr/bin/'
}

# Install nginx

package { 'nginx':
  ensure   => 'installed',
}

# Configure nginx

file_line { 'Add redirect line':
  ensure => 'present',
  path   => '/etc/nginx/sites-enabled/default',
  after  => 'server_name _;',
  line   => "location /redirect_me {\n\treturn 301 http://github.com/;\n}",
}

# Set index content

file { '/var/www/html/index.html':
  content => 'Hello World!',
}

# Restart nginx service

service { 'nginx':
  ensure  => running,
  require => Package['nginx'],
}
