# Puppet code is automating the process of fixing a typo ('phpp' to 'php')
# in the wp-settings.php file within the WordPress.

exec { 'fix-wordpress':
  command => 'sed -i s/phpp/php/g /var/www/html/wp-settings.php',
  path    => '/usr/local/bin/:/bin/'
}
