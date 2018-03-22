---
search:
    keywords: ['ffw::GuiVerticalLayout', 'GuiVerticalLayout', '~GuiVerticalLayout', 'GuiLayout', '~GuiLayout', 'addWidget', 'addWidgetAfter', 'addWidgetBefore', 'deleteWidgets', 'deleteSingleWidget', 'setOrientation', 'getMinimumWrapSize', 'setStyle', 'GuiWidget', 'GuiWidget', 'GuiWidget', 'swap', '~GuiWidget', 'setSize', 'setSize', 'setPos', 'getPos', 'getSize', 'getVisibleContentSize', 'getVisibleContentPos', 'getInnerContentSize', 'getInnerContentPos', 'getAbsolutePos', 'setOffset', 'getOffset', 'setPadding', 'setPadding', 'setPadding', 'setMargin', 'setMargin', 'setMargin', 'getPadding', 'getMargin', 'getPadding', 'getMargin', 'setMarginTop', 'setMarginRight', 'setMarginBottom', 'setMarginLeft', 'setPaddingTop', 'setPaddingRight', 'setPaddingBottom', 'setPaddingLeft', 'getPaddingInPixels', 'getMarginInPixels', 'setAlign', 'getAlign', 'setWrap', 'getWrap', 'setID', 'getID', 'update', 'render', 'shouldRedraw', 'redraw', 'invalidate', 'setParent', 'getParent', 'hasHover', 'hasFocus', 'setFocus', 'setHover', 'setDisabled', 'setHidden', 'setIgnoreUserInput', 'hide', 'show', 'isHidden', 'isDisabled', 'setFont', 'getFont', 'getCurrentFont', 'getMousePos', 'getMinimumWrapSize', 'getOuterWrapSize', 'findByID', 'addEventCallback', 'addEventCallback', 'addEventCallback', 'setTheme', 'setStyleGroup', 'getStyleGroup', 'getCurrentStyle', 'getCurrentStyle', 'getRealSize', 'getRealSizeWithMargin', 'getRealPos', 'setLineHeight', 'getLineHeight', 'setDefaults', 'getWindow', 'getWindow', 'setToggleFocus', 'setStickyFocus', 'setDropFocus', 'setDefaultFocus', 'getFocusType', 'getAllWidgets', 'pushEvent', 'operator=', 'operator=']
---

# class ffw::GuiVerticalLayout



Inherits the following classes: **[ffw::GuiLayout](classffw_1_1_gui_layout.md)**

## Public Functions

|Type|Name|
|-----|-----|
||[**GuiVerticalLayout**](classffw_1_1_gui_vertical_layout.md#1ae22c9a9117ea8ccb096e1b02843f26ae) (**[GuiWindow](classffw_1_1_gui_window.md)** \* context) |
|virtual |[**~GuiVerticalLayout**](classffw_1_1_gui_vertical_layout.md#1abcff62dd62b47f9f6a2fdda774fe008f) () |


#### Public Functions inherited from [ffw::GuiLayout](classffw_1_1_gui_layout.md)

|Type|Name|
|-----|-----|
||[**GuiLayout**](classffw_1_1_gui_layout.md#1a57d115b14e02ca4b00e8315a1b4e61d7) (**[GuiWindow](classffw_1_1_gui_window.md)** \* context, **[GuiOrientation](namespaceffw.md#1abfa7ef00a3c9c5dedf71bc95e923041f)** orientation) |
|virtual |[**~GuiLayout**](classffw_1_1_gui_layout.md#1ad51eb2e49f6f7003f8b2abf0328c6287) () |
|**[GuiWidget](classffw_1_1_gui_widget.md)** \*|[**addWidget**](classffw_1_1_gui_layout.md#1a37fc9406f3c752253c64dc93ee5110ff) (**[GuiWidget](classffw_1_1_gui_widget.md)** \* widget) |
|**[GuiWidget](classffw_1_1_gui_widget.md)** \*|[**addWidgetAfter**](classffw_1_1_gui_layout.md#1a066359deca3f33aac2028f7f2b732d8b) (const **[GuiWidget](classffw_1_1_gui_widget.md)** \* previous, **[GuiWidget](classffw_1_1_gui_widget.md)** \* widget) |
|**[GuiWidget](classffw_1_1_gui_widget.md)** \*|[**addWidgetBefore**](classffw_1_1_gui_layout.md#1a99bbdb3d366a5d01abaf3764b5856ac6) (const **[GuiWidget](classffw_1_1_gui_widget.md)** \* next, **[GuiWidget](classffw_1_1_gui_widget.md)** \* widget) |
|void|[**deleteWidgets**](classffw_1_1_gui_layout.md#1a8aa96c2644637fd682f15f0bf66a3cb4) () |
|bool|[**deleteSingleWidget**](classffw_1_1_gui_layout.md#1ae5eb1a9fd6617103e314446a97aaea5a) (const **[GuiWidget](classffw_1_1_gui_widget.md)** \* widget) |
|void|[**setOrientation**](classffw_1_1_gui_layout.md#1a055424e0ae72e3e668d2e6365714efcd) (**[GuiOrientation](namespaceffw.md#1abfa7ef00a3c9c5dedf71bc95e923041f)** orient) |
|virtual **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)**|[**getMinimumWrapSize**](classffw_1_1_gui_layout.md#1a7d1f3512522305a191721b9021f3e7ae) () override |
|void|[**setStyle**](classffw_1_1_gui_layout.md#1a7cdcba5e34ed57a09df0885148465af0) (const **[GuiLayout::Style](structffw_1_1_gui_layout_1_1_style.md)** \* style, bool defaults = false) |


#### Public Functions inherited from [ffw::GuiWidget](classffw_1_1_gui_widget.md)

|Type|Name|
|-----|-----|
||[**GuiWidget**](classffw_1_1_gui_widget.md#1ae959e47743b29d9febd9202f81ddc90e) (**[GuiWindow](classffw_1_1_gui_window.md)** \* context) |
||[**GuiWidget**](classffw_1_1_gui_widget.md#1a42a4a9ed541d36fcce97f1c8f2b4d9e7) (const **[GuiWidget](classffw_1_1_gui_widget.md)** & other) = delete |
||[**GuiWidget**](classffw_1_1_gui_widget.md#1a002c44ae8ed4747466a0c08183b402ab) (**[GuiWidget](classffw_1_1_gui_widget.md)** && other) |
|void|[**swap**](classffw_1_1_gui_widget.md#1ac850b5b5027435a732e02277a4ea53f0) (**[GuiWidget](classffw_1_1_gui_widget.md)** & other) |
|virtual |[**~GuiWidget**](classffw_1_1_gui_widget.md#1a26db5d703878ea8f579b1408419aec09) () |
|void|[**setSize**](classffw_1_1_gui_widget.md#1a3ff21c5ec8b6a59723f7fa27c311122d) (**[GuiUnits](classffw_1_1_gui_units.md)** width, **[GuiUnits](classffw_1_1_gui_units.md)** height) |
|void|[**setSize**](classffw_1_1_gui_widget.md#1a8e870e1b1d09fe045a17e23a94e5cd46) (const **[ffw::Vec2](structffw_1_1_vec2.md)**< **[GuiUnits](classffw_1_1_gui_units.md)** > & s) |
|void|[**setPos**](classffw_1_1_gui_widget.md#1a31b274bdbd69a52e9194298e73e5cd51) (**[GuiUnits](classffw_1_1_gui_units.md)** posx, **[GuiUnits](classffw_1_1_gui_units.md)** posy) |
|const **[ffw::Vec2](structffw_1_1_vec2.md)**< **[GuiUnits](classffw_1_1_gui_units.md)** > &|[**getPos**](classffw_1_1_gui_widget.md#1a7dabd5a73f1f4e06d95bf9c5a912c58c) () const |
|const **[ffw::Vec2](structffw_1_1_vec2.md)**< **[GuiUnits](classffw_1_1_gui_units.md)** > &|[**getSize**](classffw_1_1_gui_widget.md#1a5a2ae95676055c0f918ac61a5c7996df) () const |
|**[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)**|[**getVisibleContentSize**](classffw_1_1_gui_widget.md#1a9a0f469d562ad44430ae76d71e3327f4) () const |
|**[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)**|[**getVisibleContentPos**](classffw_1_1_gui_widget.md#1a7f37ebd764a7b0994ac38968c592cacd) () const |
|**[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)**|[**getInnerContentSize**](classffw_1_1_gui_widget.md#1ac0131a985bd48a55810ca19a88812191) () const |
|**[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)**|[**getInnerContentPos**](classffw_1_1_gui_widget.md#1a1f94d9ec89e4eb524d68c062d3ffe677) () const |
|**[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)**|[**getAbsolutePos**](classffw_1_1_gui_widget.md#1aa10741a8e270c1fd197e4152641a4a5f) () const |
|void|[**setOffset**](classffw_1_1_gui_widget.md#1a1e70e6b613091b64d56eed9959c1e196) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** off) |
|const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** &|[**getOffset**](classffw_1_1_gui_widget.md#1acfb69641736224aa166e1941db081ebe) () const |
|void|[**setPadding**](classffw_1_1_gui_widget.md#1ab4a6b8bce71d4b122fba6003ac0cf431) (**[GuiUnits](classffw_1_1_gui_units.md)** top, **[GuiUnits](classffw_1_1_gui_units.md)** right, **[GuiUnits](classffw_1_1_gui_units.md)** bottom, **[GuiUnits](classffw_1_1_gui_units.md)** left) |
|void|[**setPadding**](classffw_1_1_gui_widget.md#1acd88e836ff7f113b07ea0492312f5910) (**[GuiUnits](classffw_1_1_gui_units.md)** all) |
|void|[**setPadding**](classffw_1_1_gui_widget.md#1a63958ad4d489ba859173912eb4c22bd5) (const **[GuiStyle::Padding](classffw_1_1_gui_style.md#1a5f3ab2ae1509566f6558defc0ba1be6f)** & pad) |
|void|[**setMargin**](classffw_1_1_gui_widget.md#1a877d8ac241c57701d06fc0fb431ee0b7) (**[GuiUnits](classffw_1_1_gui_units.md)** top, **[GuiUnits](classffw_1_1_gui_units.md)** right, **[GuiUnits](classffw_1_1_gui_units.md)** bottom, **[GuiUnits](classffw_1_1_gui_units.md)** left) |
|void|[**setMargin**](classffw_1_1_gui_widget.md#1a72cb7ec82a4142855062d8219a1492ed) (**[GuiUnits](classffw_1_1_gui_units.md)** all) |
|void|[**setMargin**](classffw_1_1_gui_widget.md#1a242b490b827bc1b2db1068cbe3b9bede) (const **[GuiStyle::Margin](classffw_1_1_gui_style.md#1ae98f782a8de9d8eb37fc727ba8110ba1)** & mar) |
|const **[GuiStyle::Padding](classffw_1_1_gui_style.md#1a5f3ab2ae1509566f6558defc0ba1be6f)** &|[**getPadding**](classffw_1_1_gui_widget.md#1acbad267b8433713380a2883fc00185ca) () const |
|const **[GuiStyle::Margin](classffw_1_1_gui_style.md#1ae98f782a8de9d8eb37fc727ba8110ba1)** &|[**getMargin**](classffw_1_1_gui_widget.md#1a179e141cae8ba22031bc4b4f15e9826c) () const |
|**[GuiUnits](classffw_1_1_gui_units.md)**|[**getPadding**](classffw_1_1_gui_widget.md#1a169ded119a2ad6febb6f55c6e568f950) (int side) const |
|**[GuiUnits](classffw_1_1_gui_units.md)**|[**getMargin**](classffw_1_1_gui_widget.md#1a1d538beeddcd70588305c02c990c2df6) (int side) const |
|void|[**setMarginTop**](classffw_1_1_gui_widget.md#1a6fd3d0c10980e98735b6f9ef535716aa) (**[GuiUnits](classffw_1_1_gui_units.md)** val) |
|void|[**setMarginRight**](classffw_1_1_gui_widget.md#1a18db9152cf2efb8d5287a05735636a11) (**[GuiUnits](classffw_1_1_gui_units.md)** val) |
|void|[**setMarginBottom**](classffw_1_1_gui_widget.md#1a5c97ce0788131e6e21a374c5a538fd9a) (**[GuiUnits](classffw_1_1_gui_units.md)** val) |
|void|[**setMarginLeft**](classffw_1_1_gui_widget.md#1a3d2cd6ecadfb749c41e634fdbd9d0164) (**[GuiUnits](classffw_1_1_gui_units.md)** val) |
|void|[**setPaddingTop**](classffw_1_1_gui_widget.md#1a1e324755f7473ed5ca3e399232599566) (**[GuiUnits](classffw_1_1_gui_units.md)** val) |
|void|[**setPaddingRight**](classffw_1_1_gui_widget.md#1a0a0caec98677f0e1623396720a1e5b90) (**[GuiUnits](classffw_1_1_gui_units.md)** val) |
|void|[**setPaddingBottom**](classffw_1_1_gui_widget.md#1a7b5b5bdc301fcc60a586b2cee21fa3a8) (**[GuiUnits](classffw_1_1_gui_units.md)** val) |
|void|[**setPaddingLeft**](classffw_1_1_gui_widget.md#1a171e9c7ef60c565342804e3830299800) (**[GuiUnits](classffw_1_1_gui_units.md)** val) |
|float|[**getPaddingInPixels**](classffw_1_1_gui_widget.md#1a30a5726428baefefc237cfa2ab451a52) (int side) const |
|float|[**getMarginInPixels**](classffw_1_1_gui_widget.md#1afafaf4d2631b79bca4fd90f5f430373a) (int side) const |
|void|[**setAlign**](classffw_1_1_gui_widget.md#1a88f098a6bd01bd0eae06b264cb77d12e) (**[GuiAlign](group__gui_.md#ga98e6ace67ac3624f040ae5de12b2ca32)** align) |
|**[GuiAlign](group__gui_.md#ga98e6ace67ac3624f040ae5de12b2ca32)**|[**getAlign**](classffw_1_1_gui_widget.md#1a99ed1430671c42aab69df9650c6714f9) () const |
|void|[**setWrap**](classffw_1_1_gui_widget.md#1a4a5175b95e31ff0dd82fc2fee07c0230) (bool wrap) |
|bool|[**getWrap**](classffw_1_1_gui_widget.md#1a21b3260307fdbd62faddd9dbee8ef4f2) () const |
|void|[**setID**](classffw_1_1_gui_widget.md#1a16a2a505ed4a839ed1a9908c9a35fd51) (unsigned long id) |
|unsigned long|[**getID**](classffw_1_1_gui_widget.md#1afcac97163cb11c0322eacc61cb906281) () const |
|void|[**update**](classffw_1_1_gui_widget.md#1a4a70ec5d1ed0a7d8b8b17004c938f643) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & parentpos, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & parentsize, const **[GuiUserInput](classffw_1_1_gui_user_input.md)** & input, **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** mousepos, bool mouseout) |
|void|[**render**](classffw_1_1_gui_widget.md#1ab55d03daa867a74fe25f84d8974ecc70) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & clippos, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & clipsize, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & off, bool clear) |
|bool|[**shouldRedraw**](classffw_1_1_gui_widget.md#1a129178904f6fe923070c5dbc1b261a93) () const |
|void|[**redraw**](classffw_1_1_gui_widget.md#1a63ea2897579c9ee9d39295e274166386) () |
|void|[**invalidate**](classffw_1_1_gui_widget.md#1ad4acd7ac7873970a53b87bc931443213) () |
|void|[**setParent**](classffw_1_1_gui_widget.md#1a978491c33c5896639d3868fbe7d1f268) (**[GuiWidget](classffw_1_1_gui_widget.md)** \* parent) |
|const **[GuiWidget](classffw_1_1_gui_widget.md)** \*|[**getParent**](classffw_1_1_gui_widget.md#1ac7b2be4a501ea3d53f52875aad480b59) () const |
|bool|[**hasHover**](classffw_1_1_gui_widget.md#1aa83f565af49b2a06b9406fed24a7c141) () const |
|bool|[**hasFocus**](classffw_1_1_gui_widget.md#1af8fb98cb9ed25c22fb689dd8d1654204) () const |
|void|[**setFocus**](classffw_1_1_gui_widget.md#1a8773fb5eb864bd71dfae4c99fc4a5aa5) (bool f) |
|void|[**setHover**](classffw_1_1_gui_widget.md#1acef80143f19e5e8887edbf9a401bad26) (bool h) |
|void|[**setDisabled**](classffw_1_1_gui_widget.md#1aa019009d4f2479f5d61e5421156dc00a) (bool d) |
|void|[**setHidden**](classffw_1_1_gui_widget.md#1abdf66b6b198965e184f44df52014d0bc) (bool h) |
|void|[**setIgnoreUserInput**](classffw_1_1_gui_widget.md#1ab1573bedc5cba65aef885de6238e2895) (bool d) |
|void|[**hide**](classffw_1_1_gui_widget.md#1ab1103ae01a31683a63de8772950e1cd2) () |
|void|[**show**](classffw_1_1_gui_widget.md#1a415ba839e7cf59f5f6dee4d46bc670a8) () |
|bool|[**isHidden**](classffw_1_1_gui_widget.md#1a5ddefff4266d4062eafe38451856de38) () const |
|bool|[**isDisabled**](classffw_1_1_gui_widget.md#1a4b2f46d43c52c0b8762a481a664c6bdb) () const |
|void|[**setFont**](classffw_1_1_gui_widget.md#1a6ae38100832353cf3f1ba0945db66695) (const **[GuiFont](classffw_1_1_gui_font.md)** \* font) |
|const **[GuiFont](classffw_1_1_gui_font.md)** \*|[**getFont**](classffw_1_1_gui_widget.md#1a3ff9ea8acd4d83cea936a40484c69cac) () const |
|const **[GuiFont](classffw_1_1_gui_font.md)** \*|[**getCurrentFont**](classffw_1_1_gui_widget.md#1a99a25f25fe7a0e31f5e065d3444ff269) () const |
|const **[ffw::Vec2i](group__math_.md#ga8ac6bae8a24d96d0223a29ecfff14570)**|[**getMousePos**](classffw_1_1_gui_widget.md#1ac5dcc2c5f944bbe03df143bf4c63febb) () const |
|**[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)**|[**getOuterWrapSize**](classffw_1_1_gui_widget.md#1a37d30d334b8e1a9085feb7f495b06095) () |
|T \*|[**findByID**](classffw_1_1_gui_widget.md#1a90b5c2ad7362561a39a2d35120900363) (unsigned long id\_) |
|void|[**addEventCallback**](classffw_1_1_gui_widget.md#1a634935139c746539bc459cd3c6c570aa) (void(T::\*)(**[GuiEvent](classffw_1_1_gui_event.md)**) memfuncptr, T \* instance, **[GuiEventType](group__gui_.md#ga1e47d35cdb8925a93ca0dec3f77be4f0)** type = **[GuiEventType::ALL](group__gui_1gga1e47d35cdb8925a93ca0dec3f77be4.md#0a5fb1f955b45e38e31789286a1790398d)**, bool now = false) |
|void|[**addEventCallback**](classffw_1_1_gui_widget.md#1a6cb4b3f7ebe96972e01f2ee921934e39) (const std::function< void(**[GuiEvent](classffw_1_1_gui_event.md)**)> & function, **[GuiEventType](group__gui_.md#ga1e47d35cdb8925a93ca0dec3f77be4f0)** type = **[GuiEventType::ALL](group__gui_1gga1e47d35cdb8925a93ca0dec3f77be4.md#0a5fb1f955b45e38e31789286a1790398d)**, bool now = false) |
|void|[**addEventCallback**](classffw_1_1_gui_widget.md#1a92d95da6c051ea4ea2a7adf508f2aeb4) (const F & lambda, **[GuiEventType](group__gui_.md#ga1e47d35cdb8925a93ca0dec3f77be4f0)** type = **[GuiEventType::ALL](group__gui_1gga1e47d35cdb8925a93ca0dec3f77be4.md#0a5fb1f955b45e38e31789286a1790398d)**, bool now = false) |
|void|[**setTheme**](classffw_1_1_gui_widget.md#1a0c6750a5b340e86732d09fcbcbedcc96) (const **[GuiTheme](classffw_1_1_gui_theme.md)** \* theme, bool defaults = false) |
|void|[**setStyleGroup**](classffw_1_1_gui_widget.md#1a36f7fd8e37f99fb89560550ab7d625ec) (const **[GuiWidget::Style](structffw_1_1_gui_widget_1_1_style.md)** \* style) |
|const **[GuiWidget::Style](structffw_1_1_gui_widget_1_1_style.md)** \*|[**getStyleGroup**](classffw_1_1_gui_widget.md#1a3553b74bebb783ca99473e9ef2e66496) () |
|const **[ffw::GuiStyle](classffw_1_1_gui_style.md)** \*|[**getCurrentStyle**](classffw_1_1_gui_widget.md#1a735571a78d8f962bec8051dda35b44bb) () const |
|const **[ffw::GuiStyle](classffw_1_1_gui_style.md)** \*|[**getCurrentStyle**](classffw_1_1_gui_widget.md#1a43bcdfeb2b2c3914166d7bfedb5e9093) (const **[GuiWidget::Style](structffw_1_1_gui_widget_1_1_style.md)** \* group) const |
|const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** &|[**getRealSize**](classffw_1_1_gui_widget.md#1ad9bc3db78f255e59c35e971ad56dc764) () const |
|**[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)**|[**getRealSizeWithMargin**](classffw_1_1_gui_widget.md#1a0af80c8031555008973a555c6ebf8825) () const |
|const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** &|[**getRealPos**](classffw_1_1_gui_widget.md#1a0dbaafdd49981373664dd5a706e4efec) () const |
|void|[**setLineHeight**](classffw_1_1_gui_widget.md#1a18df919b806436d748a011294355728c) (float height) |
|float|[**getLineHeight**](classffw_1_1_gui_widget.md#1acfb46df33991069e3b2120918c32815e) () const |
|void|[**setDefaults**](classffw_1_1_gui_widget.md#1a71fb74bba5fb16d969e90d2ffaa1c8e1) (const **[ffw::GuiDefaults](classffw_1_1_gui_defaults.md)** \* def) |
|**[GuiWindow](classffw_1_1_gui_window.md)** \*|[**getWindow**](classffw_1_1_gui_widget.md#1ae10515c8e9f998c1447bd0d65a104a13) () |
|const **[GuiWindow](classffw_1_1_gui_window.md)** \*|[**getWindow**](classffw_1_1_gui_widget.md#1ac94c22e8c6abfe89266da9d78427c53b) () const |
|void|[**setToggleFocus**](classffw_1_1_gui_widget.md#1a1a6cdd0cc01c245b9c2773b72ce4ce7f) () |
|void|[**setStickyFocus**](classffw_1_1_gui_widget.md#1a6c3909dfe09dbd403cf4ce4c269780ba) () |
|void|[**setDropFocus**](classffw_1_1_gui_widget.md#1a64922448e25db319f0d463c1ba824d20) () |
|void|[**setDefaultFocus**](classffw_1_1_gui_widget.md#1a5c5020af5f74ea7ec1405f5c7442669e) () |
|**[GuiFocusType](namespaceffw.md#1a26e1ae45593659ea30f249a643ac4e48)**|[**getFocusType**](classffw_1_1_gui_widget.md#1aa32526d0b4442b93fadb413591706f93) () const |
|const std::vector< **[GuiWidget](classffw_1_1_gui_widget.md)** \* > &|[**getAllWidgets**](classffw_1_1_gui_widget.md#1a1a7e11bffe2617fc7ac7fc5488ef9371) () const |
|void|[**pushEvent**](classffw_1_1_gui_widget.md#1a6c394added19fc57babe969cc2a2d759) (**[GuiEventType](group__gui_.md#ga1e47d35cdb8925a93ca0dec3f77be4f0)** type, **[GuiEvent::Data](.md#unionffw_1_1_gui_event_1_1_data)** data) |
|**[GuiWidget](classffw_1_1_gui_widget.md)** &|[**operator=**](classffw_1_1_gui_widget.md#1a884f87edcbce5e6fb14bf5cb0755dae7) (const **[GuiWidget](classffw_1_1_gui_widget.md)** & other) = delete |
|**[GuiWidget](classffw_1_1_gui_widget.md)** &|[**operator=**](classffw_1_1_gui_widget.md#1a1e0e95b1915f4170d534895ea0129185) (**[GuiWidget](classffw_1_1_gui_widget.md)** && other) |


## Additional Inherited Members

#### Protected Attributes inherited from [ffw::GuiWidget](classffw_1_1_gui_widget.md)

|Type|Name|
|-----|-----|
|**[GuiWindow](classffw_1_1_gui_window.md)** \*|[**context**](classffw_1_1_gui_widget.md#1a1bae4dfa6b72128db66f70eac9cbe115)|
|const **[GuiWidget::Style](structffw_1_1_gui_widget_1_1_style.md)** \*|[**widgetStyle**](classffw_1_1_gui_widget.md#1a134b79744a36f681fc03fb193210c5bf)|


#### Protected Functions inherited from [ffw::GuiWidget](classffw_1_1_gui_widget.md)

|Type|Name|
|-----|-----|
|void|[**traverseBackground**](classffw_1_1_gui_widget.md#1aff6a202d0c8cedea7ebb0aeb34cbbc03) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & pos, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & size) |
|**[GuiWidget](classffw_1_1_gui_widget.md)** \*|[**addWidgetInternal**](classffw_1_1_gui_widget.md#1aa4b645a910fa6592cb6e0fd0845e0920) (**[GuiWidget](classffw_1_1_gui_widget.md)** \* widget) |
|**[GuiWidget](classffw_1_1_gui_widget.md)** \*|[**addWidgetAfterInternal**](classffw_1_1_gui_widget.md#1a6a9ad1c84bdeede8d4b86594813951e2) (const **[GuiWidget](classffw_1_1_gui_widget.md)** \* previous, **[GuiWidget](classffw_1_1_gui_widget.md)** \* widget) |
|**[GuiWidget](classffw_1_1_gui_widget.md)** \*|[**addWidgetBeforeInternal**](classffw_1_1_gui_widget.md#1a47d713c7f6a56624fa3b8bba68545945) (const **[GuiWidget](classffw_1_1_gui_widget.md)** \* next, **[GuiWidget](classffw_1_1_gui_widget.md)** \* widget) |
|void|[**deleteWidgetsInternal**](classffw_1_1_gui_widget.md#1ad9f9307668cb16ec09679597d1ac6e73) () |
|bool|[**deleteSingleWidgetInternal**](classffw_1_1_gui_widget.md#1a4b5b8814b97dabca8ed572e04ec2503c) (const **[GuiWidget](classffw_1_1_gui_widget.md)** \* widget) |
|void|[**setOrientationInternal**](classffw_1_1_gui_widget.md#1a5e1a04241addcbe42b01f9f6f1c52fe3) (**[GuiOrientation](namespaceffw.md#1abfa7ef00a3c9c5dedf71bc95e923041f)** orientation) |
|void|[**recalculatePos**](classffw_1_1_gui_widget.md#1a501749dfec4941ab4a1d4d0bcf714e94) () |
|void|[**recalculateSize**](classffw_1_1_gui_widget.md#1a691b21f27bdf1e7173c41dcf0c67d497) (**[GuiWidget](classffw_1_1_gui_widget.md)** \* ptr = NULL) |
|void|[**renderComponent**](classffw_1_1_gui_widget.md#1a60a6c92e4aefc5945bf20da1daadfc0b) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & pos, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & size, const **[ffw::GuiStyle](classffw_1_1_gui_style.md)** \* group) |
|virtual void|[**eventRender**](classffw_1_1_gui_widget.md#1a9a8a3007b78ef6cef68b1a406fe0d93c) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & contentoffset, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & contentsize) = 0|
|virtual void|[**eventPos**](classffw_1_1_gui_widget.md#1a27935bbc1144a3f65af01164abacc22d) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & pos) |
|virtual void|[**eventSize**](classffw_1_1_gui_widget.md#1a5b399acf7aa0800ec538636772b47229) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & size) |
|virtual void|[**eventHover**](classffw_1_1_gui_widget.md#1ac94806bac7c9b20ee6804f122565fed6) (bool gained) |
|virtual void|[**eventFocus**](classffw_1_1_gui_widget.md#1a1456d76441b98ec279f3d2dc09798711) (bool gained) |
|virtual void|[**eventMouse**](classffw_1_1_gui_widget.md#1a9ceb91203077adbfe6b2c37ad131466d) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & mousePos) |
|virtual bool|[**eventScroll**](classffw_1_1_gui_widget.md#1aeb5c2a5bc646736a04687e2f2616102f) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & scroll) |
|virtual void|[**eventMouseButton**](classffw_1_1_gui_widget.md#1ad6e3f5c5f46658da289f37a3e0e47ab1) (**[ffw::MouseButton](namespaceffw.md#1a27b70bbb6a1b35235c34a999d7420b25)** button, **[ffw::Mode](namespaceffw.md#1a7c343296bbf3216a2b78bd49ae015373)** mode) |
|virtual void|[**eventText**](classffw_1_1_gui_widget.md#1a30d702dee39cd0d765d4b618004d8fc5) (uint32\_t chr) |
|virtual void|[**eventKey**](classffw_1_1_gui_widget.md#1a02b673a69bb85f87c37460f5c22d2888) (**[ffw::Key](namespaceffw.md#1a4194e8f0528edf866a3fdfbc1ecba254)** key, **[ffw::Mode](namespaceffw.md#1a7c343296bbf3216a2b78bd49ae015373)** mode) |
|virtual void|[**eventDisabled**](classffw_1_1_gui_widget.md#1afe152a2abe0a32f46abee8a2018feab8) (bool disabled) |
|virtual void|[**eventThemeChanged**](classffw_1_1_gui_widget.md#1ade2557ce27d45a9aa8250723987e95e5) (const **[GuiTheme](classffw_1_1_gui_theme.md)** \* theme, bool defaults = false) = 0|
|const **[Flags](structffw_1_1_gui_widget_1_1_flags.md)** &|[**getFlags**](classffw_1_1_gui_widget.md#1a75d57c76b40c5f9161e27c0e3f02d8b3) () const |


## Public Functions Documentation

### function <a id="1ae22c9a9117ea8ccb096e1b02843f26ae" href="#1ae22c9a9117ea8ccb096e1b02843f26ae">GuiVerticalLayout</a>

```cpp
ffw::GuiVerticalLayout::GuiVerticalLayout (
    GuiWindow * context
)
```



### function <a id="1abcff62dd62b47f9f6a2fdda774fe008f" href="#1abcff62dd62b47f9f6a2fdda774fe008f">~GuiVerticalLayout</a>

```cpp
virtual ffw::GuiVerticalLayout::~GuiVerticalLayout ()
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/gui/guilayout.h`
