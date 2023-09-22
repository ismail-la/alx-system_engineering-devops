# Executes a bash command
# Using Puppet, create a manifest that kills a process named killmenow.
# Requirements:
#    Must use the exec Puppet resource
#    Must use pkill

exec { 'kill':
  command => 'pkill -f killmenow',
  path    => ['/usr/bin', '/usr/sbin']
}
