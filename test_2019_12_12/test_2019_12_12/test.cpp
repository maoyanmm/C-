class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == NULL || length<0)
			return;
		int i = 0;
		int oldnumber = 0;
		int replacenumber = 0;
		while (str[i] != '\0')
		{
			oldnumber++;
			if (str[i] == ' ')
			{
				replacenumber++;
			}
			i++;
		}
		int newlength = oldnumber + replacenumber * 2;
		if (newlength>length)
			return;
		int pOldlength = oldnumber;
		int pNewlength = newlength;
		while (pOldlength >= 0 && pNewlength>pOldlength)
		{
			if (str[pOldlength] == ' ')
			{
				str[pNewlength--] = '0';
				str[pNewlength--] = '2';
				str[pNewlength--] = '%';

			}
			else
			{
				str[pNewlength--] = str[pOldlength];

			}
			pOldlength--;

		}


	}
};