 
  const DEBUG= 0;
  const INFO= 1;
  const WARN= 2;
  const ERROR= 3;
  const CONSOLE= 4;
 
  var m_instance;
class Log {



  static getInstance() {
    if (!m_instance) {
      m_instance = new Log();
    }
    return m_instance;
  }

  getTimeStr() {
    var m = new Date();
    var dateString = m.getUTCFullYear() + "/" + ("0" + (m.getUTCMonth() + 1)).slice(-2) + "/" + ("0" + m.getUTCDate()).slice(-2) + " " + ("0" + m.getUTCHours()).slice(-2) + ":" + ("0" + m.getUTCMinutes()).slice(-2) + ":" + ("0" + m.getUTCSeconds()).slice(-2);

    return dateString;
  }

  constructor(type = CONSOLE) {
    this.msglevel = type;
  }

  endl() {
    return "\n";
  }

  log(type,msg){
    console.log( this.getTimeStr()  + this.getLabel(type) +" "+ msg);
  }
 
  getLabel(type) {
    var label;
    switch (type) {
      case DEBUG:
        label = "DEBUG";
        break;
      case INFO:
        label = "INFO";
        break;
      case WARN:
        label = "WARN";
        break;
      case ERROR:
        label = "ERROR";
        break;
      default:
        label = "";
        break;
    }
    return label;
  }
}
