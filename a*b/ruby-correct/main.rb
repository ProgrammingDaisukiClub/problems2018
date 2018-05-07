#!/usr/bin/ruby

n = gets.to_i
while n>0
    a, b = gets.split.map(&:to_i)
    puts a*b
    n = n-1
end
