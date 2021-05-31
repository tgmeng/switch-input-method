const { switchEnglishInputMethod, restorePreviousInputMethod } =
  require("bindings")("switch_input_method");
module.exports = {
  switchEnglishInputMethod,
  restorePreviousInputMethod,
};
