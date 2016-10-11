/* This file is part of FineFramework project */
//==============================================================================
inline ffw::VarArray::VarArray(){
}
//==============================================================================
inline ffw::VarArray::VarArray(ffw::VarArray&& Array){
    VarVec = std::move(Array.VarVec);
}
//==============================================================================
inline ffw::VarArray::VarArray(const ffw::VarArray& Array){
    VarVec = Array.VarVec;
}
//==============================================================================
inline ffw::VarArray::VarArray(std::initializer_list<Var> List){
    VarVec = List;
}
//==============================================================================
inline void ffw::VarArray::push_back(const ffw::Var& Value){
    VarVec.push_back(Value);
}
//==============================================================================
inline void ffw::VarArray::pop_back(){
    VarVec.pop_back();
}
//==============================================================================
inline std::vector<ffw::Var>::iterator ffw::VarArray::begin(){
    return VarVec.begin();
}
//==============================================================================
inline std::vector<ffw::Var>::iterator ffw::VarArray::end(){
    return VarVec.end();
}
//==============================================================================
inline void ffw::VarArray::resize(size_t Size){
    VarVec.resize(Size);
}
//==============================================================================
inline void ffw::VarArray::resize(size_t Size, const ffw::Var& Value){
    VarVec.resize(Size, Value);
}
//==============================================================================
inline size_t ffw::VarArray::size() const {
    return VarVec.size();
}
//==============================================================================
inline void ffw::VarArray::reserve(size_t Size){
    VarVec.reserve(Size);
}
//==============================================================================
inline void ffw::VarArray::clear(){
    VarVec.clear();
}
//==============================================================================
inline void ffw::VarArray::assign(size_t Size, const ffw::Var& Value){
    VarVec.assign(Size, Value);
}
//==============================================================================
inline void ffw::VarArray::assign(std::initializer_list<ffw::Var> List){
    VarVec.assign(List);
}
//==============================================================================
inline ffw::Var& ffw::VarArray::front(){
    return VarVec.front();
}
//==============================================================================
inline const ffw::Var& ffw::VarArray::front() const {
    return VarVec.front();
}
//==============================================================================
inline ffw::Var& ffw::VarArray::back(){
    return VarVec.back();
}
//==============================================================================
inline const ffw::Var& ffw::VarArray::back() const {
    return VarVec.back();
}
//==============================================================================
inline ffw::Var* ffw::VarArray::data(){
    return VarVec.data();
}
//==============================================================================
inline const ffw::Var* ffw::VarArray::data() const {
    return VarVec.data();
}
//==============================================================================
inline std::vector<ffw::Var>::reverse_iterator ffw::VarArray::rend(){
    return VarVec.rend();
}
//==============================================================================
inline std::vector<ffw::Var>::iterator ffw::VarArray::insert(std::vector<ffw::Var>::const_iterator Pos, const ffw::Var& Value){
    return VarVec.insert(Pos, Value);
}
//==============================================================================
inline std::vector<ffw::Var>::iterator ffw::VarArray::insert(std::vector<ffw::Var>::const_iterator Pos, size_t Size, const Var& Value){
    return VarVec.insert(Pos, Size, Value);
}
//==============================================================================
inline std::vector<ffw::Var>::iterator ffw::VarArray::insert(std::vector<ffw::Var>::const_iterator Pos, ffw::Var&& Value){
    return VarVec.insert(Pos, Value);
}
//==============================================================================
inline std::vector<ffw::Var>::iterator ffw::VarArray::insert(std::vector<ffw::Var>::const_iterator Pos, std::vector<Var>::iterator First, std::vector<Var>::iterator Last){
    return VarVec.insert(Pos, First, Last);
}
//==============================================================================
inline std::vector<ffw::Var>::iterator ffw::VarArray::insert(std::vector<ffw::Var>::const_iterator Pos, std::initializer_list<ffw::Var> List){
    return VarVec.insert(Pos, List);
}
//==============================================================================
inline ffw::VarArray& ffw::VarArray::operator = (const ffw::VarArray& Array){
    VarVec = Array.VarVec;
    return *this;
}
//==============================================================================
inline ffw::VarArray& ffw::VarArray::operator = (ffw::VarArray&& Array){
    VarVec = std::move(Array.VarVec);
    return *this;
}
//==============================================================================
inline ffw::VarArray& ffw::VarArray::operator = (std::initializer_list<ffw::Var> List){
    VarVec = List;
    return *this;
}
//==============================================================================
inline ffw::Var& ffw::VarArray::at(size_t i){
    return VarVec.at(i);
}
//==============================================================================
inline const ffw::Var& ffw::VarArray::at(size_t i) const {
    return VarVec.at(i);
}
//==============================================================================
inline ffw::Var& ffw::VarArray::operator[] (size_t i){
    return VarVec.at(i);
}
//==============================================================================
inline const ffw::Var& ffw::VarArray::operator[] (size_t i) const {
    return VarVec.at(i);
}
