#!/usr/bin/ruby

l = gets.chomp.to_i
i = []

l.times do
  n = gets.chomp.to_i
  str = gets.chomp.split(' ').map(&:to_i)

  i << str
end

i.each do |ary|
  result = []
  ary.each_with_index do |value, index|
    if index == 0
      result << value
    else
      result << value + result[index-1]
    end
  end
  result.each do |data|
    puts data % 2 == 0 ? 0 : 1
  end
end

