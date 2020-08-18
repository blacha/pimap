const BAD_CHAR = String.fromCharCode(255);
export const Lang = {
  data: {},
  loadLangFile(fileData: string) {
    const lines = fileData.split('\n');
    for (const line of lines) {
      const [key, ...rest] = line.split('\t');
      let words = rest.join('\t');

      let badIndex = words.indexOf(BAD_CHAR);
      while (badIndex > -1) {
        words = words.substr(0, badIndex) + words.substr(badIndex + 3);
        badIndex = words.indexOf(BAD_CHAR);
      }

      this.data[key] = words.replace('(', '').replace(')', '');
    }
  },
  t(key: string) {
    if (Lang.data[key]) {
      return Lang.data[key];
    }

    return key;
  },
};
