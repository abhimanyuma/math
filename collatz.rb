arr = (1..1_000_000).to_a
steps = {}
arr.each do |m|
  count = 0
  n = m
  while (n>1) do
    if steps[n] 
      count = steps[n] + count
      break 
    elsif ((((n/2) * 2) - n) == 0)
      n = n/2
      count += 1
    else
      n = ((3 * n) + 1) / 2
      count += 2
    end
    #count += 1
  end
  steps[m] = count
  #puts "The sequence for #{m} takes #{count} steps"
end  
