export const Lang = {
    data: {},
    loadLangFile(fileData: string) {
        const lines = fileData.split('\n')
        for (const line of lines) {
            const [key, ...rest] = line.split('\t')
            let words = rest.join('\t');
            if (words.charCodeAt(0) === 255) {
                words = words.substr(3);
            }
            this.data[key] = words
        }
    },
    t(key: string) {
        if (Lang.data[key]) {
            return Lang.data[key];
        }

        return key
    }
}
