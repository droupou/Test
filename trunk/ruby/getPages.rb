require 'net/http'

count = 0
pages = %w( www.rubycentral.com
            www.awl.com
            www.pragmaticprogrammer.com
            www.runowski.org
            www.cs.okstate.edu
            www.yahoo.com
            www.google.com
            www.msn.com
            www.creative.com
            www.slashdot.org
           )


threads = []


for page in pages
  threads << Thread.new(page) { |myPage|

    count+=1
    h = Net::HTTP.new(myPage, 80)
    puts "Fetching: #{myPage}"
    resp, data = h.get('/', nil )
    puts "Got #{myPage}:  #{resp.message}"

  }
end


threads.each { |aThread|  aThread.join }
puts()
puts(count)
