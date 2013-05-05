#!/usr/bin/ruby

x = 1.0
y = 1.01
count = 2
while y > x
  puts(y)
  y = x + 0.1*10**(-count)
  count +=1
end
puts(y)
