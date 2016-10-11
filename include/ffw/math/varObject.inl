/* This file is part of FineFramework project */
//==============================================================================
inline ffw::VarObject::VarObject(){
}
//==============================================================================
inline ffw::VarObject::VarObject(const VarObject& Object){
    VarMap = Object.VarMap;
}
//==============================================================================
inline ffw::VarObject::VarObject(VarObject&& Object){
    VarMap = std::move(Object.VarMap);
}
//==============================================================================
inline ffw::VarObject::VarObject(std::initializer_list<std::pair<const std::string, Var>> List){
    VarMap = List;
}
//==============================================================================
inline ffw::Var& ffw::VarObject::at(const std::string& Key){
    return VarMap.at(Key);
}
//==============================================================================
inline const ffw::Var& ffw::VarObject::at(const std::string& Key) const {
    return VarMap.at(Key);
}
//==============================================================================
inline std::map<std::string, ffw::Var>::iterator ffw::VarObject::begin(){
    return VarMap.begin();
}
//==============================================================================
inline std::map<std::string, ffw::Var>::iterator ffw::VarObject::end(){
    return VarMap.end();
}
//==============================================================================
inline void ffw::VarObject::clear(){
    VarMap.clear();
}
//==============================================================================
inline size_t ffw::VarObject::count(const std::string& Key) const {
    return VarMap.count(Key);
}
//==============================================================================
inline std::map<std::string, ffw::Var>::iterator ffw::VarObject::erase(const std::map<std::string, ffw::Var>::iterator Pos){
    return VarMap.erase(Pos);
}
//==============================================================================
inline std::map<std::string, ffw::Var>::size_type ffw::VarObject::erase(const std::string& Key){
    return VarMap.erase(Key);
}
//==============================================================================
inline std::map<std::string, ffw::Var>::iterator ffw::VarObject::erase(const std::map<std::string, ffw::Var>::iterator First, const std::map<std::string, ffw::Var>::iterator Last){
    return VarMap.erase(First, Last);
}
//==============================================================================
inline std::map<std::string, ffw::Var>::iterator ffw::VarObject::find(const std::string& Key){
    return VarMap.find(Key);
}
//==============================================================================
inline std::pair<std::map<std::string, ffw::Var>::iterator, bool> ffw::VarObject::insert(const std::pair<std::string, ffw::Var>& Value){
    return VarMap.insert(Value);
}
//==============================================================================
inline std::pair<std::map<std::string, ffw::Var>::iterator, bool> ffw::VarObject::insert(std::pair<std::string, ffw::Var>&& Value){
    return VarMap.insert(Value);
}
//==============================================================================
inline std::map<std::string, ffw::Var>::iterator ffw::VarObject::insert(const std::map<std::string, ffw::Var>::iterator Pos, const std::pair<std::string, ffw::Var>& Value){
    return VarMap.insert(Pos, Value);
}
//==============================================================================
inline std::map<std::string, ffw::Var>::iterator ffw::VarObject::insert(const std::map<std::string, ffw::Var>::iterator Pos, std::pair<std::string, ffw::Var>&& Value){
    return VarMap.insert(Pos, Value);
}
//==============================================================================
inline void ffw::VarObject::insert(std::map<std::string, Var>::iterator First, std::map<std::string, Var>::iterator Last){
    VarMap.insert(First, Last);
}
//==============================================================================
inline void ffw::VarObject::insert(std::initializer_list<std::pair<const std::string, ffw::Var>> List){
    VarMap.insert(List);
}
//==============================================================================
inline std::map<std::string, ffw::Var>::reverse_iterator ffw::VarObject::rend(){
    return VarMap.rend();
}
//==============================================================================
inline bool ffw::VarObject::contains(const std::string& Key) const {
    return VarMap.find(Key) != VarMap.end();
}
//==============================================================================
inline size_t ffw::VarObject::size() const {
    return VarMap.size();
}
//==============================================================================
inline ffw::VarObject& ffw::VarObject::operator = (const ffw::VarObject& Object){
    VarMap = Object.VarMap;
    return *this;
}
//==============================================================================
inline ffw::VarObject& ffw::VarObject::operator = (ffw::VarObject&& Object){
    VarMap = std::move(Object.VarMap);
    return *this;
}
//==============================================================================
inline ffw::VarObject& ffw::VarObject::operator = (std::initializer_list<std::pair<const std::string, ffw::Var>> List){
    VarMap = List;
    return *this;
}
//==============================================================================
inline ffw::Var& ffw::VarObject::operator [] (const std::string& Key){
    return VarMap.at(Key);
}
//==============================================================================
inline const ffw::Var& ffw::VarObject::operator [] (const std::string& Key) const {
    return VarMap.at(Key);
}
