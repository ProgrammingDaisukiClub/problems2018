#!/usr/bin/ruby

l = gets.chomp.to_i
know = []
zoo = []

l.times do
  n = gets.chomp.to_i
  input_know = []
  input_zoo = []

  n.times do
    input_know << gets.chomp
  end
  know << input_know

  t = gets.chomp.to_i
  t.times do
    input_zoo << gets.chomp
  end
  zoo << input_zoo
end

l.times do |index|
  seen = []

  zoo[index].each do |animal|
    if know[index].include? animal
      if seen.include? animal
        puts "moumita"
        next
      end
      puts "kawaii"
      seen << animal
    else
      puts "siranai"
    end
  end
end

