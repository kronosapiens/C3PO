require 'artoo'

connection :arduino, adaptor: :firmata, port: '127.0.0.1:8023'
device :led, driver: :led, pin: 13
device :button, driver: :button, pin: 2, interval: 0.01

work do
  puts "Press the button connected on pin #{ button.pin }..."

  on button, :push    => proc { led.on }
  on button, :release => proc { led.off }
end