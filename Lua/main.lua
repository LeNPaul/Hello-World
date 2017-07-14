test = {}

function main(Data)
   for k,v in pairs(test) do
      v()
   end
end

function test.helloWorld()
   print('Is anybody out there?')
end

function test.concatenation()
   local Value = 1
   local Line = 'We are all '..Value..' string'
   trace(Line)
end

function test.testLocalVar()
   local MyVar = 'I am a local'
   Global = 'Peace'
   testlocal()
end

function testlocal(MyVar)
   trace(Global)
   trace(MyVar)
end

function test.Types()
	local ANum = 10
   type(ANum)
   local AStr = '10'
   type(AStr)
   type(true)
   type(test)
   type(testCondition)
end

function test.testLoop()
	for i=1, 5 do
      trace(i)
   end
end

function test.whileLoop()
	local i=1
   while i < 10 do
      trace(i)
      i = i + 1
   end
   while true do
      i = i + 1
      trace(i)
      if i==18 then
         break
      end
   end
   
   myvar = 1
   repeat
      trace(myvar)
      myvar = myvar + 1
   until myvar > 10
   
end

function test.MultipleReturns()
   foo() --calls foo function, retrusn 3 values
   local A, B, three = foo() --assigns foo values to 3 variables
   trace(A)
   trace(B)
   trace(three)
end

function foo()
	return 1,2,'C'
end

function test.Colon()
   local AString = 'Houdini'
   string.sub(AString,1,3)
   AString.sub(AString,1,3)
   AString:sub(1,3)
   
end

function test.testString()
	local A = 'Never odd or even'
   A:lower()
   A:upper()
   
   A:byte(3)
   string.char(78)
   A:find('even')
   A:len()
   A:sub(1,8)
   A:sub(A:find('odd'),A:len())
   A:gsub('%s','')
   A:rep(5)
   string.rep('0',10)
   for w in A:gmatch('%a+') do
      trace(w)
   end
   
   R = A:reverse()
   --Can you make R look like this 'Never odd no even'
   
   --Lua string answers
   R = R:reverse():trimWS():gsub('%s+', ' ')
   
end

function test.testTable()
	local T = {I='inpatient',O='outpatient'}
   T['P'] = 'Preadmit'
   T.U = 'Urgent'
   for k,v in pairs(T) do
      trace(k.. '=' ..v)
    end
   trace(T)
   trace(T.U)
   
   local M = {'another','one'}
   trace(M)
   trace(M[1])
   
   --Access all global functions in a table
   trace(_G)
   
end

function test.error()
   local Success, Error = pcall(Bang)
   trace(Success)
   trace(Error)
   
   --How might we deal with pcall results?
   if Success==false then
      --log the error
      iguana.logError(Error)
      -- [[Make Iguana go to the next process
      -- or the next message]]
      return
   end
end

function Bang()
	error('A meaningful error message',1)
end

function test.testIO()
   
   --[[local F = io.open('IguanaConfiguration.xml', "r")
   local C = F:read("*a")
   F:close()
   local X = xml.parse{data=C}
   X.iguana_config.channel_config:childCount("channel")]]--
   
   local P = io.popen('dir /B')
   local File = P:read('*a')
   local List = File:split('\n')
   
   --Live in this example is set to false so that it does not connect
   --change live to true and notice the 'live' in your annotations
   local Connection = net.ftp.init{server='ftp.interfaceware.com', 
      username='training', 
      password='debut33pegs', 
      live=true
   }
   
   --Connection:put{remote_path='jefflewis.txt', data=C, overwrite=true} 

end

function test.TruePatterns()
	
   local s = 'A string!\n 1:{Act}, 2:{Cat}, 3:{Cap}'
   string.match(s, '.')

   s:match('.')   --Any Character
   s:match('%a')  --Any upper or lower case character
   s:match('%l')  --A lowercase letter
   s:match('%u')  --An UPPERCASE letter
   s:match('%p')  --Any Punctuation character
   s:match('%w')  --An alphanumberic character
   s:match('%d')  --Any digit
   s:match('%s')  --A whitespace character
   s:match('%c')  --control character like carriage return \t line feed \n backspace \b etc
   s:match('%x')  --A hexadecimal (Base 16) digit)
   s:match('%z')  --the NULL character literal '\0'

   --CAPITAL FOR OPPOSITE
   s:match('%A')  --Any NON upper or lower case character
   s:match('%L')  --An UPPERCASE letter
   s:match('%U')  --A lowercase letter
   s:match('%P')  --Any alphanumeric character
   s:match('%W')  --Any NON alphanumberic character
   s:match('%D')  --Any NON digit
   s:match('%S')  --Any NON whitespace character
   s:match('%C')  --Any non control character
   s:match('%X')  --Any non hexadecimal (Base 16) digit)
   s:match('%Z')  --Any character   
   
   string.match('I never have any $', '%$')
   
   --Quantifiers
   s:gsub('%a+', 'X')
   s:gsub('%a?', 'X')
   s:gsub('{(.-)}', 'X') -- lazy match as few characters as possible
   s:gsub('{(.*)}', 'X')
   
   --ANCHORS
   s:gsub('1:', 'X')  --Find and replace '1:' with 'X'
   s:gsub('^1:', 'X') --anchor to beginning
   s:gsub('^A ', 'X') --anchor to beginning
   s:gsub('1:$', 'X') --anchor to end
   s:gsub('%}$', 'X') --anchor to end
   s:gsub('^A.+}$', 'X') --If 'A' in the beginning and '}' at the end then replace everything 
   
   --SETS
   s:gsub('%d%p', 'X')
   s:gsub('[%d%:s]', 'X')
   s:gsub('[abc]', 'X')
   
   --RANGES
   s:gsub('[1-3]', 'X')
   s:gsub('[a-f]', 'X')
   s:gsub('[a-fA-F]', 'X')
   

   
   --COMPLEMENTS
   s:gsub('[%s]+', 'X')
   s:gsub('[^%s]+', 'X')
   s:gsub('[%{]+', 'X')
   s:gsub('[^%{]+', 'X')
      
   
   
   --CAPTURES
   s:gsub('(.)(a)', '%2%1')  --you can reference what is 'Captured'
      
end