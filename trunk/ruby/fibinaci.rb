#!/usr/bin/ruby

def fibUpTo(fr,t,lst=1)
  yield fr

  if(fr!= t)
    fibUpTo(fr+lst,t,fr)
  end  
end

fibUpTo(0,1000){|f|print f, " "}
puts()
