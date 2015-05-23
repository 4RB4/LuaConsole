local eleClass = {}

function eleClass:new(...)
	local obj = setmetatable({}, {__index = self})
	if obj.constructor then
		obj:constructor(...)
	end
	return obj;
end

function eleClass:setData(index, value)
	self.datas[index] = value
	return self.datas[index]
end

function eleClass:getData(index)
	if self.datas[index] then
		return self.datas[index]
	end
end


function eleClass:constructor(eleType)
	self.datas = {}
	
	self.ele = createElement(eleType)	
	
	self:setData("xPos", 30)
end

element = eleClass:new("Player")
--outputServerLog("uID: "..tostring(element.ele));
outputServerLog("Script loaded!");
--outputInfo()

setElementData("User", 53, 43)
