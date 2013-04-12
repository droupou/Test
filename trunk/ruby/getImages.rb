require 'net/http'

puts("Getting data...")
puts(" ")

h = Net::HTTP.new('www.runowski.org', 80)
resp, data = h.get('/renfair.html', nil)
if resp.message == "OK"
  data.scan(/<img src="(.*?)"/) { |x| puts x }
end

