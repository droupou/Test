#!/usr/bin/ruby

a = [1,2,3,4]
a.each{|x| print x, "  "}
puts()

a.push(5).reverse!.pop
a.reverse!
a.each{|x| print x, "  "}
puts()

a.push(6).reverse!.pop
a.reverse!
a.each{|x| print x, "  "}
puts()
